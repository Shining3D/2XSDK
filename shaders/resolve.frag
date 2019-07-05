#version 430 compatibility

layout (std430, binding = 0) buffer headPointer
{
  uint head_pointer[]; // 1920 * 1920, WIDTH * WEIGHT
};

layout (std430, binding = 1) buffer listData
{
  uvec4 list_buf[];
};

layout (location = 0) out vec4 color;

#define MAX_FRAGMENTS 40

uvec4 fragment_list[MAX_FRAGMENTS];

void main()
{
  ivec2 loc = ivec2(gl_FragCoord.xy);
  int frag_pos = loc.x * 2048 + loc.y;
  uint current_index = head_pointer[frag_pos];
  uint fragment_count = 0;
  while(current_index != 0 && fragment_count < MAX_FRAGMENTS)
    {
      uvec4 fragment = list_buf[current_index];
      fragment_list[fragment_count] = fragment;
      current_index = fragment.x;
      ++fragment_count;
    }
  // sort from far to near
  uint i, j;
  bool doswap = false;
  if (fragment_count > 1)
    {
      for (i = 0; i < fragment_count - 1; i++)
        {
          doswap = false;
          for (j = fragment_count-1; j > i; j--)
            {
              if (uintBitsToFloat(fragment_list[j].z) > uintBitsToFloat(fragment_list[j-1].z))
                { // swap j and j+1
                  uvec4 tmp = fragment_list[j];
                  fragment_list[j] = fragment_list[j-1];
                  fragment_list[j-1] = tmp;
                  doswap = true;
                }
            }
          if(!doswap) break;
        }
    }

  if(fragment_count == 0) discard;
  vec4 final_color = vec4(0, 0, 0, 1.0);
  for (i = 0; i < fragment_count; i++)
    {
      // here is a fix for multi sampling
      if(i>0 && abs(uintBitsToFloat(fragment_list[i-1].z)-uintBitsToFloat(fragment_list[i].z))<0.001) continue;
      vec4 modulator = unpackUnorm4x8(fragment_list[i].y);
      final_color = mix(final_color, modulator, modulator.a);
    }
  final_color.a = 0.5;
  color = final_color;
}
