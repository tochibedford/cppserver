# cppserver

A tiny HTTP-ish server written from scratch in C++, so I can have a project to work on while learning C++.

## Building it

From the project root:

```sh
mkdir -p output
clang++ -std=c++20 -Wall -Wextra -g -pedantic-errors \
  tserve.cpp networking/*/*.cpp \
  -o output/program
```

In VS Code, **Cmd+Shift+B** runs the same command via `.vscode/tasks.json`.

## Running it

```sh
sudo ./output/program
```

`sudo` is needed because the server binds to **port 80**, and on macOS/Linux
ports below 1024 are reserved for root. If you'd rather not use `sudo`, change
the port in the `TestServer` constructor in `tserve.cpp`:

```cpp
TestServer() : SimpleServer(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10)
```

then rebuild and run `./output/program` with no `sudo`.

You should see:

```
===== WAITING =====
```

## Talking to it

In another terminal:

```sh
curl http://localhost:80/
```

(or `:8080` if you changed the port). You'll get `hello from server` back, and
the server terminal will print the raw HTTP request the browser/curl sent —
that pile of `GET / HTTP/1.1` text is what a request actually looks like on the
wire. Visiting `http://localhost` in a browser works too.
