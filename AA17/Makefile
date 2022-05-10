CFLAGS = -Iheaders -std=c++17 -O2
INC=-I./headers
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

VulkanProjects: main.cpp
	g++ $(CFLAGS) $(INC) -o VulkanProject main.cpp $(LDFLAGS)

.PHONY: test clean

test: VulkanProjects
	./VulkanProject

clean:
	rm -f VulkanProject

clear:
	rm -f VulkanProject
