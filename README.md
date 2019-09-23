Graphics and Multimedia Labs

Tasks from laboratory: [__Graphics and Multimedia Labs__](https://usosweb.umk.pl/kontroler.php?_action=katalog2/przedmioty/pokazPrzedmiot&kod=1000-I1LGM)  

I used the __OOP__ paradigm, __c++__ language in standard __14__ and [__Qt library__](https://doc.qt.io) in version 5.13.0.  

---

Table of contents:
- [Running programs](#running-programs)
- [00. Test project](#00-test-project)
- [01. Drawing simple objects](#01-drawing-simple-objects)
    - [line segmet](#line-segmet)
    - [circle](#circle)
    - [ellipse](#ellipse)
    - [bézier curve](#b%C3%A9zier-curve)
    - [B-spline curve](#b-spline-curve)
- [02. Filling with color](#02-filling-with-color)
    - [flood fill](#flood-fill)
    - [scan line](#scan-line)
- [03. Color palette](#03-color-palette)
- [04. Blend modes](#04-blend-modes)
- [05. Geometric transformations for 2D objects](#05-geometric-transformations-for-2d-objects)
- [06. Texturing of triangles](#06-texturing-of-triangles)
- [07. Geometric transformations for 3d objects](#07-geometric-transformations-for-3d-objects)
- [08. Semester project - Solar System](#08-semester-project---solar-system)

---

## Running programs

To run project, you have to perform the followin commends in project catalog:  
    
    qmake
    qmake -project

Now, in catalog, you should have `project_name.pro` file. In the end of file, add line:

    QT += widgets

Now, you can use `make` to compile the project using auto generated `Makefile`.  

If you need more details you can read [this](https://wiki.qt.io/Getting_Started_on_the_Commandline)

---

## 00. Test project

In this project I checked if everything related to drawing on the widget, working with [`QImage`](https://doc.qt.io/qt-5/qimage.html), [`QPainter`](https://doc.qt.io/qt-5/qpainter.html) and [`QWidget`](https://doc.qt.io/qt-5/qwidget.html) works correctly. You can draw on the widget using the mouse.

![Test-program.gif](https://media.giphy.com/media/J4Ig56OBjXiFosI1Q9/giphy.gif)

## 01. Drawing simple objects

This is a group of projects, where you can draw simple 2D objects on `QWidget`:

#### line segmet
  
![Line-segment.gif](https://media.giphy.com/media/ck6NS9s41Ygb2rn4Hq/giphy.gif)

#### circle

![Circle.gif](https://media.giphy.com/media/VDTOHVh1wB9efIXuDR/giphy.gif)

#### ellipse
  
![Ellipse.gif](https://media.giphy.com/media/XeY0dIXmqWxCMLJUxI/giphy.gif)

#### [bézier curve](https://en.wikipedia.org/wiki/Bézier_curve)

![Bezier-curve.gif](https://media.giphy.com/media/SYFOJzyNC6nEVcoIlP/giphy.gif)

#### [B-spline curve](https://en.wikipedia.org/wiki/B-spline)

![B-spline-curve.gif](https://media.giphy.com/media/TgCBx7N2rgDCvuRc9f/giphy.gif)

## 02. Filling with color

There are two algorithms in this section:
#### [flood fill](https://en.wikipedia.org/wiki/Flood_fill)

![Flood-fill.gif](https://media.giphy.com/media/WoKVz6pFaDWyJpGNby/giphy.gif)

#### [scan line](https://en.wikipedia.org/wiki/Scanline_rendering)
  
![Scan-line.gif](https://media.giphy.com/media/dsuv0FMDJxrdteeDua/giphy.gif)

## 03. Color palette

This project is about displaying palette of colors in [RGB](https://en.wikipedia.org/wiki/RGB_color_model) and [HSV](https://en.wikipedia.org/wiki/HSL_and_HSV) convension.

![Color-palette.gif](https://media.giphy.com/media/IgKoEnq2JDsSlrtItY/giphy.gif)

## 04. Blend modes

This is project, where you can [blend](https://en.wikipedia.org/wiki/Alpha_compositing) several pictures.

![Blend-modes.gif](https://media.giphy.com/media/KH80ud9VoT1IXjoDX8/giphy.gif)

## 05. Geometric transformations for 2D objects

This is project, which show how to work geometric transformations, like 
- [translation](https://en.wikipedia.org/wiki/Translation_(geometry))
- [scaling](https://en.wikipedia.org/wiki/Scaling_(geometry))
- [rotation](https://en.wikipedia.org/wiki/Rotation_(mathematics))
- [shearing](https://en.wikipedia.org/wiki/Shear_mapping)
  
I used [homogeneous coordinates](https://en.wikipedia.org/wiki/Homogeneous_coordinates) with matrices and [bilinear interpolation](https://en.wikipedia.org/wiki/Bilinear_interpolation).

![Geometric-transformation-2D.gif](https://media.giphy.com/media/ZcntkQDB5TtmlpbErn/giphy.gif)

## 06. Texturing of triangles

In this project, you can see how to work [texturing](https://en.wikipedia.org/wiki/Texture_mapping) technique. You can checking triangle on original fragment of bitmap and mapping it on black screen. You can change position of points.

![Texturing-of-triangles.gif](https://media.giphy.com/media/mGE2Uk5GrYTAcIaNBJ/giphy.gif)

## 07. Geometric transformations for 3d objects

This is simillar project to the previous one, but in 3D space. As an example, I used a cube.

![Geometric-transformation-3D.gif](https://media.giphy.com/media/QBdBOFtiImU60bRVGX/giphy.gif)

## 08. Semester project - Solar System

Project that uses knowledge from laboratories in practice, with [shiding](https://en.wikipedia.org/wiki/Shading#Flat_shading).  

![Solar-system.gif](https://media.giphy.com/media/eGsHJPzA0m9mlZPAfh/giphy.gif)
