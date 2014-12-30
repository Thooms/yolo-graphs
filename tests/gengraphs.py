import random, sys, csv

# list of cities borrowed from http://download.geonames.org/export/dump/

if __name__ == '__main__':
    V, E = map(int, sys.argv[1:3])
    path = 'directed_{}_{}.yolo'.format(V, E)
    title = 'YOLO_{}_{}'.format(V, E)

    with open('cities15000.txt') as f:
      #print f.read()
      cities = csv.reader(f, delimiter='\t')
      cityPool = []
      for row in cities:
        cityPool.append(list(row)[2])

    random.shuffle(cityPool)

    with open(path, 'w') as f:
        f.write(title + '\n')
        
        f.write(str(V) + '\n')
        for n in cityPool[:V]:
            rname = n + '\n'
            f.write(rname)

        f.write(str(E) + '\n')
        for _ in xrange(E):
            start = random.randint(0, V-1)
            end = random.randint(0, V-1)
            typ = random.choice(['Road', 'Train', 'Plane'])
            dist = random.uniform(100.0, 3000.0)

            f.write('{} {} {} {}\n'.format(start, end, typ, dist))

    
