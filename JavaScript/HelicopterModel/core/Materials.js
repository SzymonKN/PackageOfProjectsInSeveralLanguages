function Materials() {
    //tutaj ma być pusto
}
Materials.PodstawowyMat = new THREE.MeshBasicMaterial({
    color: 0xf000ff, side: THREE.DoubleSide, wireframe: true
});

Materials.Skybox = [

 new THREE.MeshBasicMaterial({side: THREE.DoubleSide, map: THREE.ImageUtils.loadTexture('skybox/negX.jpg')}),

new THREE.MeshBasicMaterial({ side: THREE.DoubleSide, map: THREE.ImageUtils.loadTexture('skybox/posX.jpg') }),

new THREE.MeshBasicMaterial({ side: THREE.DoubleSide, map: THREE.ImageUtils.loadTexture('skybox/posY.jpg') }),

new THREE.MeshBasicMaterial({ side: THREE.DoubleSide, map: THREE.ImageUtils.loadTexture('skybox/negY.jpg') }),

new THREE.MeshBasicMaterial({ side: THREE.DoubleSide, map: THREE.ImageUtils.loadTexture('skybox/negZ.jpg') }),

new THREE.MeshBasicMaterial({ side: THREE.DoubleSide, map: THREE.ImageUtils.loadTexture('skybox/posZ.jpg') }),
];


Materials.Helikoptry = [
"Własny","Hawk",
];

Materials.HELIKOPTER1_ICONS = [
    "przod.jpg",
	"tyl.jpg",
	"gora.jpg",
    "dol.jpg",
    "poklad.jpg",
    "lewo.jpg"
	];