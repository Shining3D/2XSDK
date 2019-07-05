#version 120
varying vec4 color;
varying vec2 TextCoord0;

uniform sampler2D GlyphTexture;

void main()
{
    gl_FragColor = color * texture2D(GlyphTexture, TextCoord0).aaaa;
}
