'use strict'
new p5();
//canvas x y
var hight = 600;
var wight = 400;
//gravity
const gravity = 0.5;
//global vars or consts
//population value
var birdCount = 500;
var deadBirds = [];
var birdMass = [];
var pipeMass = [];
var geens = [];
var FrameCount = 1;
var bestBird;
var access = true;
var iteration = 0;
var bestFitness = 0;
var logicSpeed = 0.5;
var pipePassed = 0;
var pipePassedRecord = 0;
var dificulityIndex = 1;
//global vars for making diagramma of best bird
var x1_, x2_, x3_, x4_, x5_;
var y1_, y2_, y3_, y4_, y5_;
var z1_;
//index of bird will be ported to diagramm
var diagramBird = 0;

//bird class
function Bird_() {
	this.alive = true;
	this.x = wight/4;
	this.y = hight/2;
	this.gravity = gravity;
	this.fat = 30;
	this.speed = 0;
	this.distancePassed = 0;
	this.bestTubeIndex = 0;
	this.genom = [];
	this.mutateRate = 5;
	//genome creation
	for (var i = 0; i < 6; i++) {
		this.genom[i] = [];
	}
	for (var i = 0; i < 6; i++) {
		for (var j = 0; j < 5; j++) {
			this.genom[i].push(random(-1, 1));
		}
	}
	//show bird
	this.showBird = function () {
		fill(255, 80);
		stroke(3);
		ellipse(this.x, this.y, this.fat, this.fat);
	}
	this.speedChange = function() {
		this.y += this.speed;
		if (this.speed < 10) {
			this.speed += this.gravity;
			this.speed *= 0.95;
		}
		// if (this.y > hight) {
		// 	this.y = hight;
		// 	this.speed = 0;
		// }
		if (this.y - this.fat / 2 < 0) {
			this.y = this.fat / 2;
			this.speed = 0;
		}
	}
	this.fitnessCalculate = function(arr) {
		return this.distancePassed - (arr[this.bestTubeIndex].x1 + arr[this.bestTubeIndex].wight - this.x);
	}
	this.fitnessChange = function () {
		this.distancePassed += 1;
	}
	this.up = function() {
		if (this.speed > -10) {
			this.speed -= 1.5 * 10;
		}
	}
	//finding closest pipe
	this.bestTube = function(tubeMass) {
		for (var i = 0; i < tubeMass.length; i++) {
			if (tubeMass[i].x1 + tubeMass[i].wight - this.x > 0) {
				this.bestTubeIndex = i;
				return 0;
			}
		}
	}
	//detecting collision btn pipe or floor and a bird
	this.colision = function(tube) {
		function offScreen(bird) {
			if (bird.y - bird.fat / 2 > hight) {
				return true;
			} else {
				return false;
			}
		}
		function cillide(bird, tubeMass) {
			if (bird.y - bird.fat/4 < tubeMass.hight1 || bird.y + bird.fat/4 > tubeMass.hight1 + tubeMass.distance) {
				if (bird.x + bird.fat/2 > tubeMass.x1 && bird.x < tubeMass.x1 + tubeMass.wight) {
					return true;
				} else {
					return false;
				}
			} else {
				return false;
			}
		}

		if (offScreen(this) || cillide(this, tube)) {
			if (this.alive) {
				this.alive = false;
				deadBirds.push(this);
			}
		}
	}
	//brain section
	//probability function
	function sigmoid(x1, x2, x3, x4, x5, sumaps) {
		var exp = x1 * sumaps[0] + x2 * sumaps[1] + x3 * sumaps[2] + x4 * sumaps[3] + x5 * sumaps[4];
		if (1 / (1 + Math.pow(2.71828182846, -(exp))) >= 0.5) {
			return true;
		} else {
			return false;
		}
	}
	//thinking section
	this.think = function(x1, x2, x3 ,x4, x5, k) {
		var sunapsres = [];
		var suma = 0;
		for (var i = 0; i < 5; i++) {
			if (sigmoid(x1, x2, x3, x4, x5, this.genom[i])) {
				sunapsres.push(1);
			} else {
				sunapsres.push(0);
			}
		}
		if (k == diagramBird) {
			y1_ = sunapsres[0];
			y2_ = sunapsres[1];
			y3_ = sunapsres[2];
			y4_ = sunapsres[3];
			y5_ = sunapsres[4];
		}
		for (var i = 0; i < 5; i++) {
			suma += (this.genom[5][i] * sunapsres[i])
		}
		if (1 / (1 + Math.pow(2.71828182846, -suma)) >= 0.5) {
			if (k == diagramBird) {
				z1_ = 1;
			}
			return true;
		} else {
			if (k == diagramBird) {
				z1_ = 0;
			}
			return false;
		}
	}
	//mutate function
	this.mutate = function() {
		for (var i = 0; i < this.mutateRate; i++) {
			var x = Math.round(random(0, 5))
			var y = Math.round(random(0, 4))
			this.genom[x][y] = random(-1, 1);
		}
	}
}

//pipe class
function Pipe_() {
	this.distance = 200 - (2 * ((200 / (1 + Math.pow(2.71828182846, -dificulityIndex * 0.01 - 0.01))) - 150));// dificulityIndex;
	this.speed = 1.5;
	this.x1 = wight;
	this.y1 = 0;
	this.wight = 30;
	this.hight1 = random(20, 280);
	this.x2 = this.x1;
	this.y2 = this.y1 + this.hight1 + this.distance;
	this.hight2 = hight - this.y2;
	//moving and showing pipe
	this.move = function() {
		if (this.x1 + this.wight >= 100 && this.x1 + this.wight - this.speed < 100) {
			pipePassed += 1;
			if (pipePassed > pipePassedRecord){
				pipePassedRecord += 1;
			}
		}
		this.x1 -= this.speed;
		this.x2 -= this.speed;
	}
	this.showPipe = function() {
		fill(34,139,34);
		noStroke();
		rect(this.x1, this.y1, this.wight, this.hight1);
		rect(this.x2, this.y2, this.wight, this.hight2);
	}
}

//making array of individual copies of best genome
function Clone_(arr) {
	this.genom = [];
	for (var i = 0; i < arr.length; i++) {
		this.genom[i] = arr[i].slice(0);
	}
}

//detecting keys pressed and actions
function keyPressed() {
	if (keyCode === RIGHT_ARROW && logicSpeed < 10) {
  		if (logicSpeed == 0.5) {
  			logicSpeed += 0.5;
  		} else {
  			logicSpeed += 1;
  		}

  	} else if (keyCode === LEFT_ARROW && logicSpeed >= 1) {
  		if (logicSpeed == 1) {
  			logicSpeed -= 0.5;
  		} else {
  			logicSpeed -= 1;
  		}

    }
    return false;
}

//setup
function setup () {
	background(80);
	createCanvas(wight + 320, hight);
	for (var i = 0; i < birdCount; i++) {
		birdMass.push(new Bird_());
	}
	//let best bird be [0]
	bestBird = birdMass[0];
	pipeMass.push(new Pipe_());
}

//draw for loops
function draw () {
	for (var z = 0; z < logicSpeed * 2; z++) {
		//situation when all bird are dead and need to make new generation
		if (deadBirds.length == birdCount) {
			//to #zero pipe s passed
			pipePassed = 0;
			//create new pipes
			pipeMass = [];
			pipeMass.push(new Pipe_());
			FrameCount = 1;
			//count iterations (count how much generations passed)
			iteration += 1;
			//finding best geen based on best fitness
			for (var i = 0; i < birdCount; i++) {
				if (deadBirds[i].fitnessCalculate(pipeMass) > bestFitness) {
					bestFitness = deadBirds[i].fitnessCalculate(pipeMass);
					//bestBird = deadBirds[i];
					bestBird = new Clone_(deadBirds[i].genom)
				}
			}
			//clear past population
			birdMass = [];
			//create individual geens
			for (var i = 0; i < birdCount; i++) {
				geens[i] = new Clone_(bestBird.genom);
			}
			//have first without changes based on nest genome
			birdMass.push(new Bird_());
			birdMass[0].genom = bestBird.genom;
			diagramBird = 0;
			//new population based on best geen and mutated
			//let 5 bird out of all be not mutated but all new ???
			for (var i = 1; i < birdCount /*- 5*/; i++) {
				birdMass.push(new Bird_());
				birdMass[i].genom = geens[i].genom;
				birdMass[i].mutate();
			}
			// for (var i = birdCount - 5; i < birdCount; i++) {
			// 	birdMass.push(new Bird_());
			// 	//birdMass[i].genom = geens[i].genom;
			// 	//birdMass[i].mutate();
			// }
			//clean dead birds
			deadBirds = [];
		}
		//main loop when all is ok
		//pipes section
		if (FrameCount % 120 == 0) {
			pipeMass.push(new Pipe_());
		}
		if (pipeMass[0].x1 < -40) {
			pipeMass.shift();
		}
		for (var i = 0; i < pipeMass.length; i++) {
			pipeMass[i].move();
			//pipeMass[i].showPipe();
		}
		//bird section logic and calculating think function
		for (var k = 0; k < birdCount; k++) {
			if (birdMass[diagramBird].alive == false) {
				diagramBird = 0;
				while (diagramBird < birdCount - 1 && birdMass[diagramBird].alive == false) {
					diagramBird++;
				}
			}
			//finding best pipe
			birdMass[k].bestTube(pipeMass);
			//detecting collision for each bird
			birdMass[k].colision(pipeMass[birdMass[k].bestTubeIndex]);
			//thinking procces
			if (birdMass[k].alive) {
				//calculate inputs for each bird
				//distance to top pipe
				var x1 = map(pipeMass[birdMass[k].bestTubeIndex].hight1 - birdMass[k].y, -550, 400, -1, 1);
				//distance to bottom pipe
				var x2 = map(pipeMass[birdMass[k].bestTubeIndex].hight1 + pipeMass[birdMass[k].bestTubeIndex].distance - birdMass[k].y, -550, 550, -1, 1);
				//distance to pipe
				var x3 = map(pipeMass[birdMass[k].bestTubeIndex].x1 + pipeMass[birdMass[k].bestTubeIndex].wight / 2  - birdMass[k].x, 0, 180, -1, 1);
				//velocity
				var x4 = map(birdMass[k].speed, -10, 10, -1, 1);
				//disrance to bottom
				var x5 = map(birdMass[k].y - birdMass[k].fat / 2, 0, 599, -1, 1);
				//giving x1...x5 to diagram
				if (k == diagramBird) {
					x1_ = x1;
					x2_ = x2;
					x3_ = x3;
					x4_ = x4;
					x5_ = x5;
				}
				//thinking about jumping
				if (birdMass[k].think(x1, x2, x3, x4, x5, k)) {
					birdMass[k].up();
				}
				//changing bird logic, move it and other
				birdMass[k].speedChange();
				birdMass[k].fitnessChange();
			}
		}
		//counting frame s by hand ~
		FrameCount += 1;
		dificulityIndex = pipePassedRecord;
	}
	//drawing stuff finally
	//bg color
	background(135,206,250);
	//drawing pipes
	for (var i = 0; i < pipeMass.length; i++) {
		pipeMass[i].showPipe();
	}
	//draing birds
	for (var k = 0; k < birdCount; k++) {
		if (birdMass[k].alive) {
			birdMass[k].showBird();
		}
	}
	//left info table section
	//info section
	//create rect on the top of main canvas
	fill(135,206,235);
	rect(wight, 0, 320, hight);
	//text size and color
	textSize(22);
	fill(25,25,112);
	//info text and some values
	text("Gen: ", wight + 10, 30);
	text(iteration, wight + 110, 30);
	text("Fitness: ", wight + 10, 60);
	text("Record: ", wight + 10, 90);
	for (var i = 0; i < birdCount; i++) {
		if (birdMass[i].alive) {
			text(birdMass[i].distancePassed, wight + 110, 60);
			if (bestFitness == 0 || bestFitness < birdMass[i].distancePassed) {
				text(birdMass[i].distancePassed, wight + 110, 90);
			} else {
				text(bestFitness, wight + 110, 90);
			}
			break;
		}
	}
	text("Passed: ", wight + 10, 120);
	text(pipePassed, wight + 110, 120);
	text("Record: ", wight + 10, 150);
	text(pipePassedRecord, wight + 110, 150);
	text("Speed: ",wight + 10, 180);
	text("x" + logicSpeed * 2, wight + 110, 180);
	text("<- to decreese : -> to increace", wight + 10, 210);
	text(diagramBird + "/" + birdCount, wight + 110 + 50, 30);
	//diagtamm of best bird section
	//making vars for better interaction
	var x = wight;
	var y = 180 + 100;
	//lines
	for (var s = 0; s < 5; s++) {
		for (var c = 0; c < 5; c++) {
			stroke(map(bestBird.genom[s][c], -1, 1, 0, 255));
			line(x + 40, y + 25 + 50*s, x + 40 + 125, y + 25 + 50*c);
		}
	}
	for (var s = 0; s < 5; s++) {
		stroke(map(bestBird.genom[bestBird.genom.length - 1][s], -1, 1, 0, 255));
		line(x + 40 + 125, y + 25 + 50*s, x + 40 + 125 + 125, y + 25 + 50*2);
	}
	//many many dots and there color value
	var xMass = [x1_, x2_, x3_, x4_, x5_];
	var yMass = [y1_, y2_, y3_, y4_, y5_];
	var zMass = [z1_];
	//first 5 dots as inputs
	for (var i = 0; i < xMass.length; i++) {
		fill(map(xMass[i], -1, 1, 0, 255))
		ellipse(x + 40, y + 25 + 50*i, 15, 15);
	}
	//second 5 dots as hiden level
	for (var i = 0; i < yMass.length; i++) {
		fill(map(yMass[i], -1, 1, 0, 255))
		ellipse(x + 40 + 125, y + 25 + 50*i, 15, 15);
	}
	//one dot as output with is color
	fill(map(zMass[0], 0, 1, 0, 255))
	ellipse(x + 40 + 250, y + 25 + 100, 15, 15);
}
