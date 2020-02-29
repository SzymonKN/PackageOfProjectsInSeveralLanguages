function Helicopter() {
    var container = new THREE.Object3D();

    var mat = Materials.PodstawowyMat;
    var geometry1 = new THREE.CubeGeometry(200, 200, 300, 2, 2, 2);
    var geometry2 = new THREE.CubeGeometry(30, 30, 200, 2, 2, 2);
    var geometry3 = new THREE.CubeGeometry(50, 70, 50, 2, 2, 2);
    var geometry4 = new THREE.CubeGeometry(10, 10, 600, 2, 2, 2);
    var geometry5 = new THREE.CubeGeometry(10, 200, 10, 2, 2, 2);
    var kabina = new THREE.Mesh(geometry1, mat);
    var ogon = new THREE.Mesh(geometry2, mat);
    var tyl = new THREE.Mesh(geometry3, mat);
    var smiglo = new THREE.Mesh(geometry4, mat);
    var smiglo_tyl = new THREE.Mesh(geometry5, mat);
    ogon.position.z = -250;
    tyl.position.z = -360;
    smiglo.position.y = 100;
    smiglo_tyl.position.z = -360;
    smiglo_tyl.position.x = 25;
    container.add(kabina);
    container.add(ogon);
    container.add(tyl);
    container.add(smiglo);
    container.add(smiglo_tyl);
    container.position.y = 100;
  //  scene.add(container);
    
    this.getContainer = function () {
        return container;
    }
    this.update = function () {
        smiglo.rotation.y += 0.3;
        smiglo_tyl.rotation.x += 0.3;
    }
}