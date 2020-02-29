function ElementSiatki() {
    var el = new THREE.Object3D();

    var material_plane = new THREE.MeshBasicMaterial({
        color: 0x997300, side: THREE.DoubleSide, transparent: true, opacity: 0.5
    });

    var lineMaterial = new THREE.LineBasicMaterial({ color: 0xff0000 });
    var geometry = new THREE.Geometry();
    var geom = new THREE.PlaneBufferGeometry(50, 50);
    // teraz ustalamy wierzchołki wielokąta (kwadratu)
    var mesh_plane = new THREE.Mesh(geom, material_plane);
    mesh_plane.rotateX(Math.PI / 2);
    mesh_plane.position.set(25, 0, 25)
    mesh_plane.updateMatrix();
    mesh_plane.name = 'siatka';
    el.add(mesh_plane);
    geometry.vertices.push(new THREE.Vector3(0, 0, 0));
    geometry.vertices.push(new THREE.Vector3(50, 0, 0));
    geometry.vertices.push(new THREE.Vector3(50, 0, 50));
    geometry.vertices.push(new THREE.Vector3(0, 0, 50));
    geometry.vertices.push(new THREE.Vector3(0, 0, 0));


    var line = new THREE.Line(geometry, lineMaterial);
    el.add(line);

    this.getSiatka = function () {
        return el;
    }
}