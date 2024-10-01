#!/bin/bash

cd ../../../
docker rmi -f ereva/valgrind/test
docker build . -t ereva/valgrind/test -f materials/build/valgrind01/Dockerfile
docker run --rm ereva/valgrind/test
