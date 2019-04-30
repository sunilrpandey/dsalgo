#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <vector>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processUserInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
#define BUFFER_SIZE 1024


namespace LyGL
{
	GLuint vao;
	GLuint prog;
	GLuint numVertices;
	GLuint numIndices;

	class Shader
	{
		char log[BUFFER_SIZE];
		std::string shaderStr_;
		GLuint shaderType_;
		GLuint id_;
	public:
		Shader(GLuint shaderType, const std::string& shaderStr){
			shaderStr_ = shaderStr;
			shaderType_ = shaderType;			
		}
		void initShader(){
			id_ = glCreateShader(shaderType_);
			const char * shaderCode = shaderStr_.c_str();
			glShaderSource(id_, 1, &shaderCode, NULL);
		}
		bool compileShader(){
			glCompileShader(id_);			
			return checkCompileStatus();
		}
		GLuint id() { return id_; }
	private:
		bool checkCompileStatus(){
			GLint suc;
			glGetShaderiv(id_, GL_COMPILE_STATUS, &suc);
			if(!suc){
				glGetShaderInfoLog(id_, BUFFER_SIZE, 0, log);
			}
			return suc;
		}

	};
	class Program
	{
		char log[BUFFER_SIZE];
		std::string shaderStr_;
		GLuint shaderType_;
		GLuint id_;
	public:
		Program(){
			id_ = glCreateProgram();
		}
		void attachShaders(GLuint vsId, GLuint fsId){
			glAttachShader(id_, vsId);
			glAttachShader(id_, fsId);
		}
		bool linkProgram(){
			glLinkProgram(id_);
			return checkLinkStatus();
		}
		GLuint id() { return id_; }

	private:
		bool checkLinkStatus(){
			GLint suc;
			glGetProgramiv(id_, GL_LINK_STATUS, &suc);
			if(!suc){
				glGetProgramInfoLog(id_, BUFFER_SIZE, 0, log);
			}
			return suc;
		}

	};

	int setupProgram(std::string vs, std::string fs) {
		Shader vsShader(GL_VERTEX_SHADER, vs);
		vsShader.initShader();
		vsShader.compileShader();

		Shader fsShader(GL_FRAGMENT_SHADER, fs);
		fsShader.initShader();
		fsShader.compileShader();

		Program prog;
		prog.attachShaders(vsShader.id(), fsShader.id());
		prog.linkProgram();

		return prog.id();
	}
	void GetTrianglePos(vector<float>& vertices){

		float raw_vertices[] = {
			-0.5f, -0.5f, 0.0f, // left  
			0.5f, -0.5f, 0.0f, // right 
			0.0f, 0.5f, 0.0f  // top   
		};
		vertices = std::vector<float>(std::begin(raw_vertices), std::end(raw_vertices));
		return;
	}
	void GetRectPos(vector<float>& vertices){
		float zValue = 0.0f;
		float raw_vertices[] = {
			-0.5f, -0.5f, zValue, // left  
			0.5f, -0.5f, zValue, // right 
			-0.5f, 0.5f, zValue,  // top   
			0.5f, 0.5f, zValue // left  
		};
		vertices = std::vector<float>(std::begin(raw_vertices), std::end(raw_vertices));
		numVertices = vertices.size();
		return;
	}
	void GetRectColors(vector<float>& colors){
		float zValue = 0.0f;
		float raw_colors[] = {
			-0.5f, -0.5f, zValue, // left  
			0.5f, -0.5f, zValue, // right 
			-0.5f, 0.5f, zValue,  // top   
			0.5f, 0.5f, zValue // left  
		};
		colors = std::vector<float>(std::begin(raw_colors), std::end(raw_colors));
		return;
	}
	void GetRectIndices(vector<unsigned int>& indices){
		int raw_indices[] = {
			0, 1, 2,
			1, 2, 3
		};
		indices = std::vector<unsigned int>(std::begin(raw_indices), std::end(raw_indices));
		numIndices = indices.size();
	}

	int setupGeometry(std::string& vs, std::string& fs)
	{

		//Get vertices
		std::vector<float> vertices;
		LyGL::GetRectPos(vertices);
		
		std::vector<float> colors;
		LyGL::GetRectColors(colors);

		std::vector<unsigned int> indices;
		LyGL::GetRectIndices(indices);
		
		unsigned int vao = 0;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		{
			unsigned int vbo_pos = 0;
			glGenBuffers(1, &vbo_pos);
			glBindBuffer(GL_ARRAY_BUFFER, vbo_pos);
			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)NULL);
			glEnableVertexAttribArray(0);
		}
		{

			unsigned int vbo_color = 0;
			glGenBuffers(1, &vbo_color);
			glBindBuffer(GL_ARRAY_BUFFER, vbo_color);
			glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(float), &colors[0], GL_STATIC_DRAW);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)NULL);
			glEnableVertexAttribArray(1);
		}

		{
			//create ebo
			unsigned int ebo = 0;
			glGenBuffers(1, &ebo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
		}
		

		//can be done as vao is now connected to vertex attrib array, it is not bound to vbo, not necessary though
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		//never do this as vao is linked to ebo
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		//this one also not necessary as we generally enable when modification is needed.
		glBindVertexArray(0);

		vs = "#version 330 core\n"
			"layout(location = 0) in vec3 pos;\n"
			"layout(location = 1) in vec3 color;\n"
			"out vec3 outColor;\n"
			"void main() {\n"
			" gl_Position = vec4(pos,1.0);\n"
			" outColor = color;\n"
			""
			"}\n"
			;
		fs = "#version 330 core\n"
			"out vec4 fragColor;\n"
			"in vec3 outColor;\n"
			"void main() {\n"
			"fragColor = vec4(outColor,1.0f);\n"
			"}\n";

		return vao;
	}
	

	
}



void GLFWInit() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

} 

GLFWwindow* GLWindowInit()
{
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if(window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return NULL;
	}
	glfwMakeContextCurrent(window);

	//Register Window for resizing as it will change the view 
	// hence need to update viewport
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	return window;

}
void clearBuffers()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void RunRenderLoop(GLFWwindow * window)
{
	while(!glfwWindowShouldClose(window))
	{
		processUserInput(window);
		clearBuffers(); // every frame shoudl be refreshed
		
		glUseProgram(LyGL::prog);
		glBindVertexArray(LyGL::vao);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
				
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

GLFWwindow *  GLInit()
{
	// glfw: initialize and configure
	// ------------------------------
	GLFWInit();

#if 0
	// glfw window creation
	// --------------------
	GLFWwindow * window = GLWindowInit();
	if(!window){
		return NULL; // Window creation failed
	}
#endif

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return NULL;
	}

}

void GLCleanup()
{
	glfwTerminate();
}



int main()
{
	//GL init that includes init of GLFW, GLAD, GLWindow
	GLFWwindow * window = GLInit();

	std::string vs, fs;
	LyGL::vao = LyGL::setupGeometry(vs, fs);
	LyGL::prog = LyGL::setupProgram(vs, fs);
    
    // render loop
    RunRenderLoop(window);
    
	// GL Cleanup 
	GLCleanup();
	return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processUserInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
