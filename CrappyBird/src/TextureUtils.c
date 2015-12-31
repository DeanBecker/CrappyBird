#include "TextureUtils.h"

// stb_image
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

TextureData getTextureData(const char * filePath, FILE_TYPE type)
{
	TextureData textureData;
	FILE* f = fopen(filePath, "rb");
	if (!f) printf("Could not open: %s\n", filePath);

	unsigned char* data;

	if (type == BMP)
	{
		char header[54];
		int dataPos;

		if (fread(header, 1, 54, f) != 54)
			if (header[0] != 'B' || header[1] != 'M') printf("Invalid .bmp format: %s\n", filePath);

		// Header data
		dataPos = *(int *)&(header[0x0A]);
		textureData.imageSize = *(int*)&(header[0x22]);
		textureData.width = *(int *)&(header[0x12]);
		textureData.height = *(int *)&(header[0x16]);

		if (textureData.imageSize == 0) textureData.imageSize = (textureData.width * textureData.height * 3);
		if (dataPos == 0) dataPos = 54;

		data = (unsigned char*)malloc(textureData.imageSize * sizeof(unsigned char));
		fread(data, 1, textureData.imageSize, f);
	}
	else if (type == PNG)
	{
		// use stb_image to load PNG
		int comp;
		stbi_set_flip_vertically_on_load(1);
		data = stbi_load(filePath, &textureData.width, &textureData.height, &comp, STBI_rgb_alpha);
		if (!data)
		{
			printf("STB Image: Failed to load texture");
		}
	}

	fclose(f);

	glGenTextures(1, &textureData.Id);
	glBindTexture(GL_TEXTURE_2D, textureData.Id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	if (type == BMP)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureData.width, textureData.height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	}
	else if (type == PNG)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureData.width, textureData.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	if (data) free(data);

	return textureData;
}
