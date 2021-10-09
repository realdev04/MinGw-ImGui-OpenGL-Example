#include <iostream>

#include "include/imgui/imgui.h"
#include "include/imgui/imgui_impl_glfw.h"
#include "include/imgui/imgui_impl_opengl3.h"

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h"

#include "fonts.h"
#define IMGUI_WIN_FLAGS ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_::ImGuiWindowFlags_NoBackground

using namespace std;

int main(){
    cout << "starting app!\n";
    if(glfwInit() == GLFW_FALSE){
        cout << "failed to init GLFW!\n";
    }
    cout << "Initialized GLFW\n";

    //glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GL_TRUE);
    glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);
    GLFWwindow *window = glfwCreateWindow(720,480,"Hello Window", nullptr, nullptr);
    cout << "Created GLFW Window!\n";
    if(window == NULL){
        cout << "Failed to create GLFW window!\n";
        glfwTerminate();
        return -1;
    }
    //glfwSetWindowAttrib(window, GLFW_DECORATED, GLFW_FALSE);
    glfwMakeContextCurrent(window);
    cout << "Made Context Current!\n";

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImFontConfig config;
    config.OversampleH = 2;
    config.OversampleV = 1;
    config.GlyphExtraSpacing.x = 1.0f;

    ImFont *font1 = io.Fonts->AddFontFromFileTTF("fonts/ZCOOLKuaiLe-Regular.ttf", 56, &config);
    ImFont *font1s = io.Fonts->AddFontFromFileTTF("fonts/Allison-Regular.ttf", 36, &config);
    ImFont *font2 = io.Fonts->AddFontFromFileTTF("fonts/roboto/Roboto-Regular.ttf", 36, &config);
    //io.Fonts->AddFontFromMemoryCompressedTTF(&kelik_data, kelik_size, 18);
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    while(!glfwWindowShouldClose(window)){
        // render
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0, 0, 1);
        glVertex3f(-0.5, -0.5, -1);
        glColor3f(0, 1, 0);
        glVertex3f(0.5, -0.5, -1);
        glColor3f(1, 0, 1);
        glVertex3f(0.5, 0.5, -1);
        glColor3f(1, 1, 0);
        glVertex3f(-0.5, 0.5, -1);
        glEnd();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::PushFont(font1);
        bool isOpen;
        ImGui::Begin("Window", &isOpen /*,IMGUI_WIN_FLAGS*/);
        ImGui::PopFont();
        ImGui::PushFont(font2);
        ImGui::Text("Hello there!,My Name is Window");
        ImGui::PopFont();
        ImGui::PushFont(font2);
        ImGui::Text("This is a Normal Text");
        ImGui::PopFont();
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}