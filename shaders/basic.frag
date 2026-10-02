#version 460 core

uniform vec4 fragmentColor;

out vec4 screenColor;

void main() {
    screenColor = fragmentColor;
}