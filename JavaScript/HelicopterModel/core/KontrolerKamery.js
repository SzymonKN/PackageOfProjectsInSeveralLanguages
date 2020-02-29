function KontrolerKamery(cameraa, helikopter) {
    var camera = cameraa;
    var srodek = 0;

    this.update = function () {
      //  console.log("Tryb kamery    " + TrybyKamery.WYBRANY_TRYB);
       // console.log(camera)
        switch (TrybyKamery.WYBRANY_TRYB) {
            case 0:
                //TrybyKamery.TYL
                //ustaw kamerę z tyłu helikoptera
                //na takiej samej zasadzie jak 
                //w projekcie z modelem
                camVect = new THREE.Vector3(0, 1000, 1000);
                //jeśli zmieniasz fov:
               // camera.updateProjectionMatrix();
                break;
            case '2':
                //TrybyKamery.TYL
        //ustaw kamerę z tyłu helikoptera
        //na takiej samej zasadzie jak 
                //w projekcie z modelem
                srodek = 0;
		camVect = new THREE.Vector3(0, 200, 1000);
        //jeśli zmieniasz fov:
        //camera.updateProjectionMatrix();
        break;
            case '1':
                //TrybyKamery.Przod
                //ustaw kamerę z tyłu helikoptera
                //na takiej samej zasadzie jak 
                //w projekcie z modelem
                srodek = 0;
                camVect = new THREE.Vector3(0, 200, -1000);
                //jeśli zmieniasz fov:
               // camera.updateProjectionMatrix();
                break;
        
           case '3':
    //TrybyKamery.Gora
    //ustaw kamerę z tyłu helikoptera
    //na takiej samej zasadzie jak 
               //w projekcie z modelem
               srodek = 0;
    camVect = new THREE.Vector3(0, 1500, 10);
    //jeśli zmieniasz fov:
    // camera.updateProjectionMatrix();
    break;
            case '4':
                //TrybyKamery.Dol
                //ustaw kamerę z tyłu helikoptera
                //na takiej samej zasadzie jak 
                //w projekcie z modelem
                srodek = 0;
                camVect = new THREE.Vector3(0,-1500, 10);
                //jeśli zmieniasz fov:
                // camera.updateProjectionMatrix();
                break;
            case '5':
                //TrybyKamery.Kabina
                //ustaw kamerę z tyłu helikoptera
                //na takiej samej zasadzie jak 
                //w projekcie z modelem
                srodek = 1;
                camVect = new THREE.Vector3(0, 120, -95);
                //jeśli zmieniasz fov:
                camera.updateProjectionMatrix();
                break;
            case '6':
                //TrybyKamery.lewo
                //ustaw kamerę z tyłu helikoptera
                //na takiej samej zasadzie jak 
                //w projekcie z modelem
                srodek = 0;
                camVect = new THREE.Vector3(-1000, 200, 0);
                //jeśli zmieniasz fov:
                // camera.updateProjectionMatrix();
                break;
}



        var camPos = camVect.applyMatrix4(helikopter.matrixWorld);
        camera.position.set(camPos.x, camPos.y, camPos.z);
        if (srodek == 0)
            camera.lookAt(helikopter.position);
        else {
            var dal = new THREE.Vector3(helikopter.position.x, helikopter.position.y, helikopter.position.z - 2000)
            camera.lookAt(dal)
         
        }
      //  console.log(camPos.z +'                '+helikopter.position.z)
    }
}