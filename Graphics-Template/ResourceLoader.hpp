/*
- ResourceLoader.hpp
-
- Author: 100086865
-
*/

#pragma once

#include <map>
#include <string>

#include "Texture.hpp";
#include "Shader.hpp";

class ResourceLoader {

	//Maps to store the resources (shaders and textures <Resource Name><Resource>)
	static std::map<std::string, Shader> shaders;
	static std::map<std::string, Texture2D> textures;

	/*
	- Builds and loads a shader program from shader source files
	- @param: Vertex shader source file
	- @param: Fragment shader source file
	- @param: (Optional) Geometry shader source file
	- @param: Name for the resource
	- @return: Shader program
	*/
	static Shader loadShader(GLchar *vertexShaderFile, GLchar *fragmentShaderFile, GLchar *geometryShaderFile, std::string name);

	/*
	- Gets a stored shader
	- @param: Shader name
	- @return: Requested shader
	*/
	static Shader getShader(std::string name);

	/*
	- Loads a texture from a file
	- @param: Image file
	- @param: Alpha  
	- @param: Texture name
	- @return: Texture generated from an image file
	*/
	static Texture2D loadTexture(GLchar *file, GLboolean alpha, std::string name);

	/*
	- Gets a stored texture
	- @param: Texture name
	- @return: Requested texture
	*/
	static Texture2D getTexture(std::string name);

	/*
	- Clear all resources
	*/
	static void clear();

private:
	/*
	- Private constructor (Singleton class, we do not want any objects)
	*/
	ResourceLoader() {}

	/*
	- Loads and generates a shader from a file
	- @param: Vertex shader source file
	- @param: Fragment shader source file
	- @param: (Optional) Geometry shader source file
	- @return: A shader loaded from the file
	*/
	static Shader loadShaderFromFile(const GLchar *vertexShaderFile, const GLchar *fragmentShaderFile, const GLchar *geometryShaderFile = nullptr);

	/*
	- Loads and generates a texure from a file
	- @param:Texture image file	
	- @param: Alpha
	- @return: A texture generated from an image file
	*/
	static Texture2D loadTextureFromFile(GLchar *file, GLboolean alpha);
};