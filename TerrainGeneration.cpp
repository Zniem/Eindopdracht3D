#include "TerrainGeneration.h"
#define STB_IMAGE_IMPLEMENTATION
std::vector<float> TerrainGeneration::GenerateTerrain() {
    int width, height, channels;
    unsigned char* data = stbi_load("models/noiseTexture.png", &width, &height, &channels, 1);
    if (!data) {
        std::cerr << "Failed to load image\n";
        //return -1;
    }
    std::vector<float> heightmap(width * height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char pixel = data[y * width + x];
            float heightValue = pixel;  // Normalize 0–1
            heightmap[y * width + x] = heightValue;
            //std::cout << heightValue << std::endl;
        }
    }
    stbi_image_free(data);
    return heightmap;
}