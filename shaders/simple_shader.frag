#version 450

// layout qualifier (it takes a location value)
// the fragment shader **can** output to multiple location.
// but we use it only to output on location 0.

layout (location = 0) out vec4 outColor;

void main() {
    outColor = vec4(1.0, 0.0, 0.0, 1.0);
}
