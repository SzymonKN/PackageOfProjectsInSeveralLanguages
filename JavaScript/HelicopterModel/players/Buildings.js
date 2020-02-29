function Buildings() {
    var loader = new THREE.ColladaLoader();
    var model;
    var container = new THREE.Object3D();
  //  var nazwa = "Big_Old_House/BOH.xml";
    var nazwa = "models/model.xml";
    
    this.loadModel = function(skala) {
     
        loader.load(
          
              nazwa,
              // gdy załadowany
              function (collada) {
              
                  model = collada.scene;

                  // dostęp do meshów wewnątrz modelu
                  // używamy gdy chcemy zrobić coś z elementami modelu
                  // np podstawić materiał
              
                  model.traverse(function (child) {

                      if (child instanceof THREE.Mesh) {                      
                         // console.log("mesh uuuuuuuuuuuuuuuuuuuu" + child.id);                      

                          //child.material = new THREE.MeshBasicMaterial({color:0xffff00})
                      }

                  });

                  container.add(model);
                 // console.log("LADOWANIE");
                  //poprawki skali, położenia, obrotu
                  model.scale.set(50,50,50);
                 model.rotation.x = -1.58;
                 model.position.set(2000, 0, 0);
                 var mat = new THREE.MeshBasicMaterial({
                     color: 0xffffff, side: THREE.DoubleSide, wireframe: true
                 });
                  var geom = new THREE.PlaneBufferGeometry(10000, 10000,10,10);
                  var mesh = new THREE.Mesh(geom, mat);
                  mesh.rotateX(1.57);
                  container.add(mesh);
                  var light1 = new THREE.DirectionalLight(0xffffff, 1);
                    light1.position.set(0, 1,0 );
                  //     light1.lookAt(mesh.position);
              
                    container.add(light1);

              },
              // gdy model jest pobierany z serwera
          //jest możliwe monitorowanie stanu jego pobierania
          //i wykonanie jakiejś czynności dopiero po załadowaniu

              function (e) {
                  console.log("model " + e.loaded +"-"+e.total)
              }
          );
      
    }
    this.getBuild = function () {
        return container;

    }
   
}