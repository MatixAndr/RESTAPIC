# RESTAPIC
An simple REST API in C


## Compilation

REQUIRED:
- [MSYS](https://www.msys2.org)
  - JSON-C `pacman -S mingw-w64-x86_64-json-c`

```bash
gcc -o server main.c server.c routes.c user.c -ljson-c -lws2_32
```