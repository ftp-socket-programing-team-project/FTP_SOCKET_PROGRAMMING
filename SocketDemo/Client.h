// TCP Client header file
#pragma once

// Need to add socket library
#pragma comment(lib,"Ws2_32.lib")

//disable inetPton()
#pragma warning(disable:4996) 

//STD console header files
#include<stdio.h>
#include<conio.h>

//SOCKET header files
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <string>
#define SOK_VERSION2 0x0202

