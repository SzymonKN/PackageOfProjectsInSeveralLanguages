function Klocek() {

    var obj = new THREE.Object3D();

    var geometryA = new THREE.CubeGeometry(50, 30, 50, 1, 1, 1);
    var geometryB = new THREE.CylinderGeometry(8, 8, 8, 64, 1);
    var meshA = new THREE.Mesh(geometryA) 
    var meshB = new THREE.Mesh(geometryB)
    var meshC = new THREE.Mesh(geometryB)
    var meshD = new THREE.Mesh(geometryB)
    var meshE = new THREE.Mesh(geometryB)
    var anyMaterial = new THREE.MeshBasicMaterial({ 
        color: 0x00ff00, side: THREE.DoubleSide
    });

    var materialK = new THREE.MeshPhongMaterial({
        color: 0x00ff00, side: THREE.DoubleSide,
    });
    //ustawiamy ich pozycje
    meshA.position.set(0, 15, 0);
    meshB.position.set(-15, 30, -15);
    meshC.position.set(15, 30, 15);
    meshE.position.set(-15, 30, 15);
    meshD.position.set(15, 30, -15);

    var singleGeometry = new THREE.Geometry();

    meshA.updateMatrix(); // bez tego pozycja geometrii jest zawsze 0,0,0
    singleGeometry.merge(meshA.geometry, meshA.matrix);

    meshB.updateMatrix(); 
    singleGeometry.merge(meshB.geometry, meshB.matrix);

    meshC.updateMatrix();
    singleGeometry.merge(meshC.geometry, meshC.matrix);
    meshD.updateMatrix();
    singleGeometry.merge(meshD.geometry, meshD.matrix);
    meshE.updateMatrix();
    singleGeometry.merge(meshE.geometry, meshE.matrix);

    var singleMesh = new THREE.Mesh(singleGeometry, materialK);
    singleMesh.name = 'klocek'
    obj.add(singleMesh);
    this.getKlocek = function () {
        return obj;

    }

}