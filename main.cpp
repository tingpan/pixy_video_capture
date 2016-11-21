//
// Created by TingMiao on 20/11/2016.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "PixyCamera.h"

using namespace std;

void handle_SIGINT(int unused)
{
    // On CTRL+C - abort //

    printf("\nBye!\n");
    exit(0);
}

int main() {
    signal(SIGINT, handle_SIGINT);
    PixyCamera p;

    if (p.Test() == 0) {

        Mat pixy_image = p.GetOneFrame();

        namedWindow("Image", WINDOW_NORMAL);
        imshow("Image", pixy_image);

        waitKey(0);

    } else {
        cout << "Pixy camera error, exit";
        exit(-1);
    }
}