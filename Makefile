br:
	g++ main.cpp -Llib/GLEW -lglew32 -Llib/GLFW -Llib/imgui -limgui -lopengl32 -lglfw3 -lgdi32 -luser32 -lkernel32 -o main
	./main
build:
	g++ main.cpp -Llib/GLEW -lglew32 -Llib/GLFW -Llib/imgui -limgui -lopengl32 -lglfw3 -lgdi32 -luser32 -lkernel32 -o main
run:
	./main