in vec4 TexCoords;
in vec4 ParticleColor;
out vec4 color;

uniform sampler2D sprite;

void
main() {
    color = (texture(sprite, TexCoords.st) * ParticleColor);
}
