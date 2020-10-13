if exist result (
    del result
)
for /f %%f in ('dir /b .\test') do azul.exe -t test\%%f >> result
fc /b base_line result> nul

if errorlevel 1 (
    fc base_line result
) else (
    echo "test result is the same"
)
