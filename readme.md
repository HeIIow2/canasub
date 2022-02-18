# SIA - Uboot

Dies ist das Projekt für SIA 2021 - 2022. Es ist ein Uboot dass eine leuchtende Blackbox bergen soll.

## Klasse - Motor

- ena
- in1
- in2

### Funktion - halt

stoppt den Motor

### Funktion - forwards

schaltet die Drehrichtung des Motors nach vorne

### Funktion - backwards

schaltet die Drehrichtung des Motors nach hinten

### Funktion - set_speed

- speed `0.0 - 1.0`

ändert die Drehgeschwindigkeit des Motors

## Klasse - LightSensor

- analog Pin

### Funktion - get_value

gibt den gemessenen Wert zurück `0.0 - 1.0`