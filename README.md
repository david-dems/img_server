# HTTP image server.

## What does it do?
Server recieves clients request with JPEG image. Image contains in request body in binary format. This server flips image horizontally and send it back to the client. 
This project is implemented with POCO C++ and CImg.

## Prerequirenments
- X Window System -- X11
- libjpeg (jpeglib.h jerror.h)
- Threads library -- pthreads
- GCC/g++
- CMake
- Make

## Building (via CMake & Make)

Tested only with UNIX (Ubuntu 20.04).
It is not sophisticated to build this project.
Clone this with:
```
git clone https://github.com/david-dems/img_server.git --recursive
```
Just run following commands in base directory of the project:
```
cmake .
make
```
Executable file img_server will appear in directory ./bin.

## Runtime
After running ./img_server message will appear: Server has been started working.
Now it is possible to make request:
```
curl -s --data-binary @image.jpg 127.0.0.1:5875 -o out.jpg -v
```
In file out.jpg will contains flipped copy of image.jpg.
If the image does not exist or it is not JPEG, the server will return BadRequest(400) and reason.
You can turn server off with interrupt CTRL+C from UNIX command line. It is the standard shutdown method.
