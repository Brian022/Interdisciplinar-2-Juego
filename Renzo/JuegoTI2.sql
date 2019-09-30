create database Juego;
use Juego;
create table Usuario(
	Nickname varchar(200) not null,
    Contraseña varchar(200) not null,
    Puntaje int not null
)ENGINE=InnoDB;
create table Personaje(
	Nombreper varchar(200) not null,
    Nickuser varchar(200) not null,
    Vida int not null,
    Bando varchar(200) not null,
    Elegible bool
)ENGINE=InnoDB;
create table Nivel(
	Codnivel int not null,
    Objetivos varchar(2000) not null
)ENGINE=InnoDB;
create table Escenario(
	Codescenario int not null,
    Codni int not null,
    Nombrees varchar(200) not null
)ENGINE=InnoDB;
create table Item(
	Codesce int not null,
    Codpers varchar(200) not null,
    Codcap int not null,
    CodItem int not null,
    Nombreit varchar(200) not null,
    Descripcion varchar(2000) not null
)ENGINE=InnoDB;
create table Objeto(
	Codobjeto int not null,
    Codescen int not null,
    Nombreob varchar(200) not null
)ENGINE=InnoDB;
create table Plataforma(
	Codobjetop int not null,
    Codplat int not null,
    Tipo varchar(200) not null
)ENGINE=InnoDB;
create table Capsula(
	Codobjetoc int not null,
    Codcapsula int not null,
    Tipo varchar(200) not null
)ENGINE=InnoDB;
create table ProblemaM(
	Codprob int not null,
    Codcapsu int not null,
    Enunciado varchar(2000) not null,
    Correcto bool not null,
    Valor int not null
)ENGINE=InnoDB;
create table PartidaG(
	Codpar int not null,
    Codniv int not null,
    Codp varchar(200) not null
)ENGINE=InnoDB;

ALTER TABLE Usuario ADD CONSTRAINT PK_User PRIMARY KEY(Nickname);
ALTER TABLE Personaje ADD CONSTRAINT PK_Personaje PRIMARY KEY(Nombreper);
ALTER TABLE Nivel ADD CONSTRAINT PK_Nivel PRIMARY KEY(Codnivel);
ALTER TABLE Escenario ADD CONSTRAINT PK_Escenario PRIMARY KEY(Codescenario);
ALTER TABLE Item ADD CONSTRAINT PK_Item PRIMARY KEY(CodItem);
ALTER TABLE Objeto ADD CONSTRAINT PK_Objeto PRIMARY KEY(Codobjeto);
ALTER TABLE Plataforma ADD CONSTRAINT PK_Plat PRIMARY KEY(Codplat);
ALTER TABLE Capsula ADD CONSTRAINT PK_Caps PRIMARY KEY(Codcapsula);
ALTER TABLE ProblemaM ADD CONSTRAINT PK_Prob PRIMARY KEY(Codprob);
ALTER TABLE PartidaG ADD CONSTRAINT PK_Part PRIMARY KEY(Codpar);

ALTER TABLE Personaje ADD CONSTRAINT CO_Per FOREIGN KEY PK_Per(Nickuser)REFERENCES Usuario(Nickname)
ON DELETE NO ACTION
ON UPDATE CASCADE;
ALTER TABLE Escenario ADD CONSTRAINT CO_Es FOREIGN KEY PK_Es(Codni)REFERENCES Nivel(Codnivel)
ON DELETE NO ACTION
ON UPDATE CASCADE;
ALTER TABLE Item ADD CONSTRAINT CO_It1 FOREIGN KEY PK_It1(Codesce)REFERENCES Escenario(Codescenario)
ON DELETE NO ACTION
ON UPDATE CASCADE;
ALTER TABLE Item ADD CONSTRAINT CO_It2 FOREIGN KEY PK_It2(Codpers)REFERENCES Personaje(Nombreper)
ON DELETE NO ACTION
ON UPDATE CASCADE;
ALTER TABLE Item ADD CONSTRAINT CO_It3 FOREIGN KEY PK_It3(Codcap)REFERENCES Capsula(Codcapsula)
ON DELETE NO ACTION
ON UPDATE CASCADE;
ALTER TABLE Objeto ADD CONSTRAINT CO_Ob FOREIGN KEY PK_Ob(Codescen)REFERENCES Escenario(Codescenario)
ON DELETE NO ACTION
ON UPDATE CASCADE;
ALTER TABLE Plataforma ADD CONSTRAINT CO_Plat FOREIGN KEY PK_Plat(Codobjetop)REFERENCES Objeto(Codobjeto)
ON DELETE NO ACTION
ON UPDATE CASCADE;
ALTER TABLE Capsula ADD CONSTRAINT CO_Caps FOREIGN KEY PK_Caps(Codobjetoc)REFERENCES Objeto(Codobjeto)
ON DELETE NO ACTION
ON UPDATE CASCADE;
ALTER TABLE ProblemaM ADD CONSTRAINT CO_Prob1 FOREIGN KEY PK_Prob1(Codcapsu)REFERENCES Capsula(Codcapsula)
ON DELETE NO ACTION
ON UPDATE CASCADE;
ALTER TABLE PartidaG ADD CONSTRAINT CO_Par1 FOREIGN KEY PK_Par1(Codniv)REFERENCES Nivel(Codnivel)
ON DELETE NO ACTION
ON UPDATE CASCADE;
ALTER TABLE PartidaG ADD CONSTRAINT CO_Par2 FOREIGN KEY PK_Par2(Codp)REFERENCES Personaje(Nombreper)
ON DELETE NO ACTION
ON UPDATE CASCADE;