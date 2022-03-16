// Create a matrix for Perspecrtive projection with the given aspect ratio a,
// and a FovY = 90o
glm::mat4 PO1(float a) {
	float n = 0.1;
	float f = 9.9;
	glm::mat4 out = glm::perspective(glm::radians(90.0f), a, n, f);
	out[1][1] *= -1;
	return out;
}

// Create a matrix for Perspecrtive projection with the given aspect ratio a,
// and a FovY = 120o
glm::mat4 PO2(float a) {
	float n = 0.1;
	float f = 9.9;
	glm::mat4 out = glm::perspective(glm::radians(120.0f), a, n, f);
	out[1][1] *= -1;
	return out;
}

// Create a matrix for Perspecrtive projection with the given aspect ratio a,
// and a FovY = 30o
glm::mat4 PO3(float a) {
	float n = 0.1;
	float f = 9.9;
	glm::mat4 out = glm::perspective(glm::radians(30.0f), a, n, f);
	out[1][1] *= -1;
	return out;
}

// Create a matrix for Perspecrtive projection, with the given aspect ratio a.
// Here the perspective should only show the left side of the view
// with a FovY = 90o. Here r=0, and l, t and b should be computed
// to match both the aspect ratio and the FovY
glm::mat4 PO4(float a) {
	float n = 0.1;
	float f = 9.9;
	float r = 0.0;
	float l = -a*n*tan(45.0);
	float t = n*tan(45.0);
	float b = -n*tan(45.0);
	glm::mat4 furst = glm::frustum(l, r, b, t, n, f);
	glm::mat4 scale = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1));
	glm::mat4 out = scale*furst;
	return out;
}

