## Overview
C++ base developing environment with docker & cmake, cpplint & google test

## Require Tools
- docker -v: ex. 20.10.13
- docker-compose -v: ex. 1.29.2

## Usage

### Create docker image
- `docker-compose build` or `docker-compose build --no-cache`

### Start docker container
- `docker-compose up -d`
- `docker-compose run dev bash`  # if you want to check inside of the container

### dlls
- `docker-compose exec dev ../bash/add_dll.sh <dll name>` # Create new dll
- `docker-compose exec dev ../bash/delete_dll.sh <dll name>` # Delete dll

### Build(ubuntu18)

- `docker-compose exec dev cmake ..`
- `docker-compose exec dev make`
- `docker-compose exec dev ./src/my_app`  # execute app

### Lint(CppLint)
For example,
- `docker-compose exec dev cpplint ../src/exe/main.cpp`
- `docker-compose exec dev cpplint ../src/my_math_dll/my_math.cpp`
- `docker-compose exec dev cpplint ../src/hello_dll/hello.cpp`

### Tests(Google Tests)
For example,
- `docker-compose exec dev ctest --verbose` # all tests
- `docker-compose exec dev src/hello_test`
- `docker-compose exec dev src/my_math_test`

### Stop docker container
- `docker-compose down`  # if finish developing

### Others
- `docker-compose ps`  # check docker image status

## References

- [c++ with docker](https://qiita.com/kai_kou/items/1f4b9a45a5d4d6788649)
- [coenvl/googletest
](https://hub.docker.com/r/coenvl/googletest/dockerfile)
- [Ceate better google test env](https://www.jonki.net/entry/2016/06/15/220029)
- [cpp development env widh docker](https://qiita.com/n-jun-k2/items/1b84b5b99351fb835035)
