#version 330 core

#ifdef GL_ES
// Set default precision to high
precision highp int;
precision highp float;
#endif

uniform sampler2D texture;
varying vec4 v_texcoord;


void
main() {
    // Set fragment color from texture
    gl_FragColor = texture2D(texture, v_texcoord.st);
}

