@echo off
setlocal enabledelayedexpansion

:: Konfiguracja ścieżek i narzędzi
set CC=gcc
set CFLAGS=-Wall -Wextra -std=c11 -I"C:/msys64/mingw64/include"
set LDFLAGS=-L"C:/msys64/mingw64/lib" -mconsole
set LIBS=-ljson-c -lws2_32

:: Katalogi
set SRC_DIR=src
set BUILD_DIR=build

:: Czyszczenie poprzedniej kompilacji
if exist %BUILD_DIR% rmdir /s /q %BUILD_DIR%
mkdir %BUILD_DIR%

:: Kompilacja plików źródłowych
%CC% %CFLAGS% ^
    %SRC_DIR%/main.c ^
    %SRC_DIR%/server.c ^
    %SRC_DIR%/routes.c ^
    %SRC_DIR%/user.c ^
    -o %BUILD_DIR%/server.exe ^
    %LDFLAGS% %LIBS%

if %errorlevel% neq 0 (
    echo Kompilacja zakończona niepowodzeniem
    exit /b %errorlevel%
)

echo Kompilacja zakończona sukcesem
%BUILD_DIR%/server.exe