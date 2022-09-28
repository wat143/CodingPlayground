// This is testure sample code in "https://web.cs.upb.de/cgvb/WebGLEditor/".
// Steps to run
// 1. Paste VS and FS to each tabs
/*** VS ***
attribute vec3 a_vertex;
attribute vec2 a_texCoord;
//attribute vec3 a_normal;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

varying vec2 v_texcoord;
//varying vec4 fColor;

void main() {
    // Pass the texcoord to the fragment shader.
     v_texcoord = a_texCoord;
    gl_Position = projection * view* model* vec4(a_vertex.xyz, 1.0);
}
***/
/*** FS ***
// fragment shaders don't have a default precision so we need
// to pick one; mediump is a good default
precision mediump float;
varying vec2 v_texcoord;
// The texture.
uniform sampler2D u_texture;
void main() {

    gl_FragColor = texture2D(u_texture, v_texcoord);
}
***/
// 2. Paste main code to editor

var obj = {
    'cerberusObj': "./src/object/cerberus.obj"
};

var tex = {
    'cerberusTex': "./src/texture/cerberus.jpg"
};

OBJ.downloadMeshes(obj, myCallback);
// Enable depth testing, used for hidden surface removal
gl.enable(gl.DEPTH_TEST);
// Near things obscure far things
gl.depthFunc(gl.LEQUAL);
//Load shaders and initialize
var program = initShaders(gl);
gl.useProgram(program);

TEX.downloadTextures(tex, texCallback);
var myCerberusTex;

function texCallback(texture) {
    myCerberusTex = texture.cerberusTex;

    gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, true);
    TEX.initTextureBuffer(gl, myCerberusTex);
}

var texcoordLocation = gl.getAttribLocation(program, "a_texCoord");
gl.enableVertexAttribArray(texcoordLocation);

var vertPos = gl.getAttribLocation(program, "a_vertex");
gl.enableVertexAttribArray(vertPos);

var mycerberusObj;
function myCallback(mesh) {
    mycerberusObj = mesh.cerberusObj;
    // create and initialize the vertex, vertex normal, and texture coordinate buffers
    // and save on to the mesh object
    OBJ.initMeshBuffers(gl, mycerberusObj);
}

var viewPostition;
var viewMatrix;
viewMatrix = mat4.create();
lookAtArcballCamera(viewMatrix, vec3.fromValues(0, 0, 1), vec3.fromValues(0, 0, 0), vec3.fromValues(0, 1, 0));
var projectionMatrix = mat4.create();
mat4.perspective(projectionMatrix, 45, gl.canvas.width / gl.canvas.height, 0.1, 1000);
