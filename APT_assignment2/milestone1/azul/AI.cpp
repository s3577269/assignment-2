#include "AI.h"
#include "Type.h"

#include <set>
#include <map>
#include <sstream>

struct Move
{

    Move(size_t nf, Tile t, size_t np, size_t ns, size_t na);
    std::string toString() const;

    size_t numFactory;
    Tile tile;
    size_t numPatternLine;

    size_t numTileStay;
    size_t numTileAbandon;
};


Move::Move(size_t nf, Tile t, size_t np, size_t ns, size_t na):
    numFactory(nf), tile(t), numPatternLine(np), numTileStay(ns), numTileAbandon(na) {}

std::string Move::toString() const
{
    std::ostringstream ss;
    ss << "turn ";
    ss << numFactory;
    ss << " ";
    ss << convertToChar(tile);
    ss << " ";
    ss << numPatternLine + 1; // pattern line is 1 indexed
    return ss.str();
}

std::string computeNextMove(const std::vector<Factory*>& factories, const Player* const player)
{

    // initialize factories map: (id of factory, (tile, number of tile))
    size_t numFilledFactories = 1;
    std::map<size_t, std::map<Tile, size_t>> facotriesMap;    
    for (size_t i = 0; i < factories.size(); i++)
    {
        const auto& numbers = factories[i]->tileNumbers();
        facotriesMap[i] = numbers;
        if(!numbers.empty() && i!=0)
        {
            numFilledFactories++;
        }
    }

    // initilize pattern lines map: (tile, [list of pattern line ids that have this tile])
    std::map<Tile, std::vector<size_t>> patternLinesMap;
    std::map<size_t, size_t> patternLinesSlots;
    patternLinesMap[NO_TILE] = std::vector<size_t>{};
    const auto& pattern = player->getMosaic()->getPattern();    
    for (size_t i = 0; i < ROW; i++)
    {
        patternLinesSlots[i] = 0;
        const auto& patternLine = pattern->getPatternLine(i);
        bool noTile = true;
        for (size_t j = 0; j < patternLine.size(); j++)
        {
            auto t = patternLine[j];
            if (t!=NO_TILE)
            {
                noTile = false;
                if (patternLinesMap.find(t) != patternLinesMap.end())
                {
                    patternLinesMap[t].push_back(i);
                }
                else
                {
                    patternLinesMap[t] = std::vector<size_t>{i};
                }                
            } else
            {
                patternLinesSlots[i]++;
            }
            
        }
        if (noTile)
        {
            patternLinesMap[NO_TILE].push_back(i);
        }                
    }
    
    // initialize wall map: (id, (set of exisiting tile))
    std::map<size_t, std::set<Tile>> wallMap;
    const auto& wall = player->getMosaic()->getWall();
    for (size_t i = 0; i < ROW; i++)
    {
        wallMap.emplace(i, wall->existingTiles(i));
    }
    
    // compute possible moves
    const size_t floor = ROW;
    std::map<std::string, Move> possibleMoves;
    for (const auto& f: facotriesMap)
    {
        for (const auto& tn: f.second)
        {
            if (tn.first != FIRST_PLAYER)
            {
                std::vector<size_t> availablePattern;
                std::copy(patternLinesMap[NO_TILE].begin(), patternLinesMap[NO_TILE].end(), std::back_inserter(availablePattern));

                if(patternLinesMap.find(tn.first) != patternLinesMap.end())
                {
                    std::copy(patternLinesMap[tn.first].begin(), patternLinesMap[tn.first].end(), std::back_inserter(availablePattern));
                }
                
                availablePattern.push_back(floor); // floor is always a possible move

                for (size_t i = 0; i < availablePattern.size(); i++)
                {
                    size_t row = availablePattern[i];
                    if (row ==floor || (patternLinesSlots[row]>0 && wallMap[row].find(tn.first) == wallMap[row].end()))
                    {
                        size_t abandon = row ==floor ? tn.second:
                            patternLinesSlots[row] >= tn.second ? 0: tn.second - patternLinesSlots[row];
                        size_t stay = row == floor? 0 : patternLinesSlots[row];
                        Move m(f.first, tn.first, row, stay, abandon);
                        const auto& key = m.toString();
                        possibleMoves.emplace(key, m);
                    }
                    
                }
            }
        }
    }
    
    double maxScore = -100;
    std::string bestMove;
    for (const auto& move: possibleMoves)
    {
        auto m = move.second;
        double score = static_cast<double>(m.numTileStay)/(m.numPatternLine+1)-m.numTileAbandon*patternLinesSlots[m.numPatternLine];
        if (m.numPatternLine != floor)
        {
            score += wall->computeScore(m.tile, m.numPatternLine)/static_cast<double>(patternLinesSlots[m.numPatternLine]);
        }

        if(score>maxScore)
        {
            maxScore = score;
            bestMove = move.first;
        }
    }
    
    return bestMove;
}