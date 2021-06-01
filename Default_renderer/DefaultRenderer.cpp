#include "DefaultRenderer.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <MEE_Graphics.h>


#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


void DefaultRenderer::onInit(int pl_id)
{
	std::cout << "[DefaultRenderer] Is starting" << std::endl;
	MEE_setWindowName(std::string("Joaquin"));
	MEE_bindRenderClear(pl_id, "renderClear");
	MEE_bindinitGL(pl_id, "initGL");
}


void DefaultRenderer::onLoad()
{
	std::cout << "[DefaultRenderer] onLoad() called!" << std::endl;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, 5 * 4 * sizeof(GLfloat), base_quad_buffer_data, GL_STATIC_DRAW);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), indices, GL_STATIC_DRAW);

	GLintptr offset = 2 * sizeof(float);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		0            // array buffer offset
	);
	glVertexAttribPointer(
		1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		2,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(GLvoid*) offset            // array buffer offset
	);


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);



	shader = LoadShaders("C:/Work/T_Plugins/x64/Default_renderer/Shaders/shader.vert", "C:/Work/T_Plugins/x64/Default_renderer/Shaders/shader.frag");

	glGetUniformLocation(shader, "textureSlot");

	texture.load("C:/Users/rarat/Pictures/games.png");
	std::cout << texture.getRendererID() << '\n';
	texture2.load("C:/Users/rarat/Pictures/games.png");
	std::cout << texture2.getRendererID() << '\n';
}

void DefaultRenderer::initGL()
{
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f); //Esto va en InitGL
		//Initialize Projection Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Initialize Modelview Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


}

void DefaultRenderer::renderClear()
{
	//glClearColor(0, 0, 0, 1); //Esto va en InitGL
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void DefaultRenderer::renderQuad()
{
	glClearColor(0.4f, 0.0f, 0.4f, 0.0f);

	glUseProgram(shader);
	texture.bind(GL_TEXTURE0);
	//texture2.bind(0);
	glUniform1i(textureSlot, 0);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	//glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,nullptr); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

}

//Código tomado de https://www.opengl-tutorial.org/beginners-tutorials/tutorial-2-the-first-triangle/
GLuint DefaultRenderer::LoadShaders(const char* vertex_file_path, const char* fragment_file_path) {

	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
	if (VertexShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << VertexShaderStream.rdbuf();
		VertexShaderCode = sstr.str();
		VertexShaderStream.close();
	}
	else {
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
		return 0;
	}

	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
	if (FragmentShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << FragmentShaderStream.rdbuf();
		FragmentShaderCode = sstr.str();
		FragmentShaderStream.close();
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const* VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}

	// Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const* FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
	glCompileShader(FragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}

	// Link the program
	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}


	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;
}


void DefaultRenderer::onShutdown()
{
	std::cout << "[DefaultRenderer] onShutdown() called!" << std::endl;
}