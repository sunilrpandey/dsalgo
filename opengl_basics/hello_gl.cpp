#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <vector>
using namespace std;
/* Notes
When using glVertexAttribPointer() everything gets cast to a float. While glVertexAttribIPointer() can only expose vertex arrays that store integers and glVertexAttribLPointer() is only for doubles.
*/

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processUserInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
#define BUFFER_SIZE 1024


namespace LyGL
{
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
	int setupGeometry(std::string& vs, std::string& fs)
	{

		//Get vertices
		std::vector<float> vertices;
		LyGL::GetTrianglePos(vertices);
		unsigned int vao = 0;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		unsigned int vbo = 0;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)NULL);
		glEnableVertexAttribArray(0);

		//can be done as vao is now connected to vertex attrib array, it is not bound to vbo, not necessary though
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		//this one also not necessary as we generally enable when modification is needed.
		glBindVertexArray(0);

		vs = "#version 330 core\n"
			"layout(location = 0) in vec3 pos;\n"
			"void main() {\n"
			" gl_Position = vec4(pos,1.0);\n"
			"}\n"
			;
		fs = "#version 330 core\n"
			"out vec4 fragColor;\n"
			"void main() {\n"
			"fragColor = vec4(1.0f,0.0f,0.0f,1.0f);\n"
			"}\n";

		return vao;
	}
	

	GLuint vao;
	GLuint prog;	
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
		glDrawArrays(GL_TRIANGLES, 0, 3);
				
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
