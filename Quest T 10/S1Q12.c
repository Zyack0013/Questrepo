// 12.Edge Detection Algorithm
// Function Prototype: void detectEdges(const unsigned char *image, unsigned char *edges, int width, int height)
// Data Types: const unsigned char*, unsigned char*, int
// Concepts: Loops, arrays, decision-making, functions.
// Details: Detect edges in an image, updating the edges array by reference.


#include <stdio.h>
#include <math.h>

void detectEdges(unsigned char const *image, unsigned char *edges, int width, int height);

int main() {

    int width = 5,height = 5;
    unsigned char image[25] = {

        10,20,30,40,50,
        60,70,80,90,100,
        110,120,130,140,150,
        160,170,180,190,200,
        210,220,230,240,250

    };

    unsigned char edges[25] = {0};

    detectEdges(image, edges, width, height);

    printf("Edge Detected Image:\n");

    for(int i = 0; i < height; i++) {

        for(int j = 0; j < width; j++) {

            printf("%3d ", edges[i * width + j]);

        }
        printf("\n");
    }



    return 0;
}

void detectEdges(unsigned char const *image, unsigned char *edges, int width, int height) {

    int gx[3][3] = {

        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}

    };

    int gy[3][3] = {

        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}

    };


    for(int i = 1; i < height - 1; i++) {

        for(int j = 1; j < width - 1; j++) {

            int gxSum = 0, gySum = 0;

            
            for(int di = -1; di <= 1; di++) {

                for(int dj = -1; dj <= 1; dj++) {

                    int pixel = image[(i + di) * width + (j + dj)];

                    gxSum += gx[di + 1][dj + 1] * pixel;
                    gySum += gy[di + 1][dj + 1] * pixel;

                }
            }

            
            int magnitude = (int)sqrt(gxSum * gxSum + gySum * gySum);

            
            edges[i * width + j] = (magnitude > 255) ? 255 : magnitude;
        }
    }


}