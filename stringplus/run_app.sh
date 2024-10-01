docker build -t myimage:imege1 -f Dockerfile .

docker run -it --name App -d --rm -v "$PWD":/my_app myimage:imege1

docker exec -it App bash  

