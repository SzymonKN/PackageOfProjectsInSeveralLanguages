function Dobudowanie() {

    var obj = new THREE.Object3D();

    var geometryA = new THREE.CubeGeometry(25, 30, 50, 1, 1, 1);
    var geometryB = new THREE.CylinderGeometry(8, 10, 8, 64, 1);
    var meshA = new THREE.Mesh(geometryA)
    var meshB = new THREE.Mesh(geometryB)
    var meshC = new THREE.Mesh(geometryB)

    var anyMaterial = new THREE.MeshBasicMaterial({
        color: 0x00ff00, side: THREE.DoubleSide
    });

    var materialK = new THREE.MeshPhongMaterial({
        color: 0x00ff00, side: THREE.DoubleSide,
    });
    //ustawiamy ich pozycje
    meshA.position.set(-13, 15, 0);
    meshB.position.set(-15, 30, -15);
    meshC.position.set(-15, 30, 15);
   // meshC.position.set(40, 30, 40);


    var singleGeometry = new THREE.Geometry();

    meshA.updateMatrix(); // bez tego pozycja geometrii jest zawsze 0,0,0
    singleGeometry.merge(meshA.geometry, meshA.matrix);

    meshB.updateMatrix();
    singleGeometry.merge(meshB.geometry, meshB.matrix);

    meshC.updateMatrix();
    singleGeometry.merge(meshC.geometry, meshC.matrix);
   
    var singleMesh = new THREE.Mesh(singleGeometry, materialK);
    singleMesh.name = 'klocek'
   
    this.getDob = function () {
        return singleMesh;

    }

}