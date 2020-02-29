function Helikopter2() {
    var loader = new THREE.ColladaLoader();
    var model;
    var container = new THREE.Object3D();
    //  var nazwa = "Big_Old_House/BOH.xml";
    var nazwa = "models/hawk.xml";
    var wirnik;
    var wirnik2;
    this.loadModel1 = function (skala) {

        loader.load(

                   




              nazwa,
              // gdy załadowany
              function (collada) {
                  model = collada.scene;
                
                  wirnik = model.getObjectByName("main_rotor", true)
                 
                  wirnik2 = model.getObjectByName("rear_rotor", true)
                  // o tym mowa w punkcie  2         
                  container.add(model);
                  //wyskaluj model
                //  model.scale.set(500,500,500);
                

                  // dostęp do meshów wewnątrz modelu
                  // używamy gdy chcemy zrobić coś z elementami modelu
                  // np podstawić materiał

                  model.traverse(function (child) {

                      if (child instanceof THREE.Mesh) {
                           console.log("meshH" + child.id);                      

                          //child.material = new THREE.MeshBasicMaterial({color:0xffff00})
                      }

                  });

                  container.add(model);
                  // console.log("LADOWANIE");
                  //poprawki skali, położenia, obrotu
                  model.scale.set(500, 500, 500);
                  model.rotation.x = -1.58;
                  model.position.set(0, -200, 0);
                 


                

              },
              // gdy model jest pobierany z serwera
          //jest możliwe monitorowanie stanu jego pobierania
          //i wykonanie jakiejś czynności dopiero po załadowaniu

              function (e) {
                  console.log("model " + e.loaded + "-" + e.total)
              }
          );

    }
    this.ladujGo = function () {
        return container;

    }
    this.Wirniki = function () {
        return wirnik2;
    }
    this.updateWir = function () {
       // if(wirnik)
       wirnik.rotation.z += 0.6;
      //  wirnik2.rotation.x += 0.4;
    }
}