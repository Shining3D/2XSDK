#version 430 core

uniform vec4 line_color;

void main()
{
  gl_FragColor = line_color;
  //gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
