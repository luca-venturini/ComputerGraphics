// Rotate 45 degrees around an arbitrary axis passing through (1,0,-1). 
// The x-axis can be aligned to the arbitrary axis after a rotation of 
// 30 degrees around the z-axis, and then -60 degrees around the y-axis.

glm::mat4 tr1 = glm::translate(glm::mat4(1), glm::vec3(1, 0, -1));
glm::mat4 rotz = glm::rotate(glm::mat4(1), glm::radians(30.0f), glm::vec3(0, 0, 1));
glm::mat4 roty = glm::rotate(glm::mat4(1), glm::radians(-60.0f), glm::vec3(0, 1, 0));
glm::mat4 rot = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(1, 0, 0));

glm::mat4 MT1 = tr1 * roty * rotz * rot * inverse(rotz) * inverse(roty) * inverse(tr1);


// Half the size of an object, using as fixed point (5,0,-2)
glm::mat4 tr2 = glm::translate(glm::mat4(1), glm::vec3(5, 0, -2));
glm::mat4 scale = glm::scale(glm::mat4(1), glm::vec3(0.5, 0.5, 0.5));

glm::mat4 MT2 = tr2 * scale * inverse(tr2);


// Mirror the starship along a plane passing through (1,1,1), 
// and obtained rotating 15 degree around the x axis the xz plane

glm::mat4 tr3 = glm::translate(glm::mat4(1), glm::vec3(1, 1, 1));
glm::mat4 rotx = glm::rotate(glm::mat4(1), glm::radians(15.0f), glm::vec3(1, 0, 0));
glm::mat4 mirror = glm::scale(glm::mat4(1), glm::vec3(1, -1, 1));

glm::mat4 MT3 = tr3 * rotx * mirror * inverse(rotx) * inverse(tr3);


// Apply the inverse of the following sequence of transforms: 
// Translation of (0, 0, 5) then rotation of 30 degree around the Y axis, 
// and finally a uniform scaling of a factor of 3.

glm::mat4 tr4 = glm::translate(glm::mat4(1), glm::vec3(0, 0, 5));
glm::mat4 roty4 = glm::rotate(glm::mat4(1), glm::radians(30.0f), glm::vec3(0, 1, 0));
glm::mat4 scale4 = glm::scale(glm::mat4(1), glm::vec3(3, 3, 3));

glm::mat4 MT4 = inverse(tr4) * inverse(roty4) * inverse(scale4);
