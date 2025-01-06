// 11.Computer Vision
// Image Filter Application
// Function Prototype: void applyFilter(const unsigned char *image, unsigned char *filteredImage, int width, int height)
// Data Types: const unsigned char*, unsigned char*, int
// Concepts: Arrays, pointers, functions.
// Details: Apply a filter to an image, modifying the filtered image by reference.


#include <stdio.h>

void applyFilter(unsigned char const *image, unsigned char *filteredImage, int width, int height);

int main() {

    int width = 4,height = 4;
    unsigned char image[16] = {

        10,20,30,40,
        50,60,70,80,
        90,100,110,120,
        130,140,150,160
    };
    unsigned char filteredImage[16] = {0};

    applyFilter(image,filteredImage,width,height);

    printf("Filtered Image:\n");
    
    for(int i = 0; i < height; i++) {
    
        for(int j = 0; j < width; j++) {
    
            printf("%3d ", filteredImage[i * width + j]);
    
        }
    
        printf("\n");
    
    }


    return 0;
}


void applyFilter(unsigned char const *image, unsigned char *filteredImage, int width, int height) {

    for(int i = 0;i < width;i++) {

        for(int j = 0;j < height;j++) {

            int sum = 0,count = 0; 

              for (int di = -1; di <= 1; di++) {

                for (int dj = -1; dj <= 1; dj++) {

                    int ni = i + di; 
                    int nj = j + dj; 

                    
                    if(ni >= 0 && ni < height && nj >= 0 && nj < width) {

                        sum += image[ni * width + nj];
                        count++;
                    }
                }
            }

            filteredImage[i * width + j] = sum / count;
        }


    }

}