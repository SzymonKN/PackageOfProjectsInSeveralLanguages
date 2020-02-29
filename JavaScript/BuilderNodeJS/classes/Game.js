function Game() {
   
  this.getPlansza = function (scene) {
      for (i = 0; i < 15; i++) {
          for (j = 0; j < 15; j++) {
              var siatka = new ElementSiatki();
              var elementS = siatka.getSiatka();
           //   elementS.position.x = j * 50 - 500;
             // elementS.position.y = 0;
             // elementS.position.z = i * 50 - 500;
              elementS.children[0].position.x = j * 50 - 500;
              elementS.children[0].position.z = i * 50 - 500;
              elementS.children[1].position.x = j * 50 - 500-25;
              elementS.children[1].position.z = i * 50 - 500-25;
              scene.add(elementS)
               console.log(elementS.children[0])
          }
      }
  scene.add(siatka.getSiatka())

  }
}