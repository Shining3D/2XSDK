#version 430 compatibility
out vec4 color;
void main()
{
    color = gl_Color;
    gl_Position = ftransform();
}
