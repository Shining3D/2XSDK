#version 430 compatibility
layout (early_fragment_tests) in;
uniform vec3 line_color_u;
uniform gl_MaterialParameters gl_FrontMaterial;

layout (std430, binding = 0) buffer headPointer
{
  uint head_pointer[]; // 1920 * 1920, WIDTH * WEIGHT
};

layout (std430, binding = 1) buffer listData
{
  uvec4 list_buf[];
};

layout (binding = 0, offset = 0) uniform atomic_uint list_counter;

in vec3 normal;
flat in vec3 inpt[3];

void main()
{
  vec4 mat_color = gl_FrontMaterial.diffuse;
  vec4 line_color = vec4(line_color_u.x, line_color_u.y, line_color_u.z, 1.0);
  vec3 lightDir = normalize(gl_LightSource[0].position.xyz);

  float costheta = dot(normal, lightDir);
  float a = costheta * 0.5 + 0.5;
  mat_color.xyz = a * mat_color.xyz;

  //float diff = 0.2 + 0.8 * dot(normal, lightDir);
  //mat_color.xyz = mat_color.xyz * diff;
  
  vec3 tmp_coord = vec3(gl_FragCoord.x, gl_FragCoord.y, 0);
  float tmp_0 = length(cross((tmp_coord - inpt[0]), normalize(inpt[1] - inpt[0])));
  float tmp_1 = length(cross((tmp_coord - inpt[1]), normalize(inpt[1] - inpt[2])));
  float tmp_2 = length(cross((tmp_coord - inpt[2]), normalize(inpt[2] - inpt[0])));
  float half_fill_width = 0.5;
  float half_smooth_width = 1.0;
  float edge_factor = min(min(tmp_0, tmp_1), tmp_2);
  if(edge_factor < half_fill_width) {
  	mat_color = line_color;
  } else { // smooth area
  	float d = 2/half_smooth_width * (edge_factor - half_fill_width);
  	float i = exp2(-2 * d * d);
  	mat_color = i * line_color + (1-i) * mat_color;
  }
  // if fully constsruct the link list
  if(mat_color.a < 0.99f) {
	ivec2 loc = ivec2(gl_FragCoord.xy);
	int frag_pos = loc.x * 2048 + loc.y;
	uint new_head = atomicCounterIncrement(list_counter);
	uint old_head = atomicExchange(head_pointer[frag_pos], new_head);
	list_buf[new_head].x = old_head;
	list_buf[new_head].y = packUnorm4x8(mat_color);
	list_buf[new_head].z = floatBitsToUint(gl_FragCoord.z);
	discard;
  } else {
	gl_FragColor = mat_color;
  }
}