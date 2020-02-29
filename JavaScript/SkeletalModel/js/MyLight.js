function MyLight() {

    //zmienne, np: materiał i geometria sfery
    var geometry = new THREE.SphereGeometry(10, 10, 10);
    var material= new THREE.MeshBasicMaterial({
        color: 0x0000ff, side: THREE.DoubleSide, wireframe: true
    });

    // kontener
    var container = new THREE.Object3D();

    // init
    function init() {
        var sphere = new THREE.Mesh(geometry, material);
        var light1 = new THREE.SpotLight(0xffffff, 10, 2000, 3.14);
      //  light1.position.set(0, 400,0 );
   //     light1.lookAt(mesh.position);
        container.add(sphere);
        container.add(light1);
        // tu utwórz światło, sferę oraz helper

        // i dodaj je do powyższego kontenera
    }





    init();

    // funkcja publiczna zwracająca obiekt kontenera
    // czyli nasze światło

    this.getLight = function () {
        return container;

    }

    // inne funkcje publiczne potrzebne do manipulacji światłem



};