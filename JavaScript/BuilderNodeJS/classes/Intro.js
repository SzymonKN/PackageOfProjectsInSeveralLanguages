function Intro() {
    var textGeometry = new THREE.TextGeometry(
           "BOB THE BUILDER", {
               font: "arial",
               height: 30,
               size: 60
           });
    var materialT = new THREE.MeshPhongMaterial({
        color: 0x0000ff, side: THREE.DoubleSide, 
    });
    var mesh = new THREE.Mesh(textGeometry, materialT);
    mesh.position.x = -500;
    mesh.position.z = 0;
    mesh.position.y = 0;

    this.getText = function () {

        return mesh;
    };


}