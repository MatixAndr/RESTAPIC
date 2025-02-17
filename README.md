# RESTAPIC

Prosty serwer REST API napisany w C++ implementujący podstawowe operacje CRUD (Create, Read, Update, Delete) dla zarządzania użytkownikami.

| Build Status | Windows 10 Build | Windows 11 Build | License | Last Commit | Issues |
|--------------|------------------|------------------|---------|-------------|--------|
| ![Build Status](https://github.com/MatixAndr09/RESTAPIC/actions/workflows/makefile.yml/badge.svg) | ![Windows 10 Build](https://github.com/MatixAndr09/RESTAPIC/actions/workflows/makefile.yml/badge.svg?branch=master&event=push) | ![Windows 11 Build](https://github.com/MatixAndr09/RESTAPIC/actions/workflows/makefile.yml/badge.svg?branch=master&event=push) | ![License](https://img.shields.io/github/license/MatixAndr09/RESTAPIC) | ![Last Commit](https://img.shields.io/github/last-commit/MatixAndr09/RESTAPIC) | ![Issues](https://img.shields.io/github/issues/MatixAndr09/RESTAPIC) |

## Opis

RESTAPIC to lekki i wydajny serwer REST API zaimplementowany w C++ z wykorzystaniem WinSock2 dla obsługi połączeń sieciowych. Projekt oferuje podstawową funkcjonalność zarządzania użytkownikami poprzez standardowe endpointy HTTP.

### Główne funkcje

- Serwer HTTP nasłuchujący na porcie 8888
- Pełna implementacja operacji CRUD dla użytkowników
- Obsługa żądań HTTP (GET, POST, PUT, PATCH, DELETE)
- Komunikacja w formacie JSON
- Testy integracyjne zapewniające poprawność działania

### Endpointy API

- `GET /users` - pobieranie listy wszystkich użytkowników
- `GET /users/{id}` - pobieranie szczegółów konkretnego użytkownika
- `POST /users` - tworzenie nowego użytkownika
- `PUT /users/{id}` - całkowita aktualizacja użytkownika
- `PATCH /users/{id}` - częściowa aktualizacja użytkownika
- `DELETE /users/{id}` - usuwanie użytkownika

## Wymagania systemowe

- System Windows
- Kompilator C++ (G++)
- Make

## Instalacja i uruchomienie

1. Sklonuj repozytorium:
```bash
git clone https://github.com/MatixAndr09/RESTAPIC.git
cd RESTAPIC
```
2. Skompiluj projekt:
```bash
make
```
3. Uruchom serwer:
```bash
./restapic.exe
```
