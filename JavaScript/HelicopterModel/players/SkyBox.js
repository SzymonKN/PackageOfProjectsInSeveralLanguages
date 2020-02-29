function SkyBox() {

    var geometryS = new THREE.CubeGeometry(10000, 10000, 10000, 1, 1, 1);
    var faceMaterial = new THREE.MeshFaceMaterial(Materials.Skybox);

    var mesh = new THREE.Mesh(geometryS, faceMaterial);
   




    this.getSky = function () {
        return mesh;
    }


}