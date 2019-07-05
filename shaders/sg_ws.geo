#version 330
layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;
uniform vec2 viewport_u;
in vec3 vnormal[];
out vec3 normal;
flat out vec3 inpt[3];
void main()
{
  float half_width = viewport_u.x/2; // input viewport half width
  float half_height = viewport_u.y/2; // input viewport half height
  inpt[0] = vec3(half_width * (gl_in[0].gl_Position.x/gl_in[0].gl_Position.w+1), half_height * (gl_in[0].gl_Position.y/gl_in[0].gl_Position.w+1), 0);
  inpt[1] = vec3(half_width * (gl_in[1].gl_Position.x/gl_in[1].gl_Position.w+1), half_height * (gl_in[1].gl_Position.y/gl_in[1].gl_Position.w+1), 0);
  inpt[2] = vec3(half_width * (gl_in[2].gl_Position.x/gl_in[2].gl_Position.w+1), half_height * (gl_in[2].gl_Position.y/gl_in[2].gl_Position.w+1), 0);
  gl_Position = gl_in[0].gl_Position;
  normal = vnormal[0];
  EmitVertex();

  gl_Position = gl_in[1].gl_Position;
  normal = vnormal[1];
  EmitVertex();

  gl_Position = gl_in[2].gl_Position;
  normal = vnormal[2];
  EmitVertex();
  EndPrimitive();
}