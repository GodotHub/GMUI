class_name FileUtils extends RefCounted

static func xml_to_scene_path(path):
	return path.replace('res://layouts', 'res://scenes').replace('.xml', '.tscn')

static func scene_to_xml_path(path):
	return path.replace('res://scenes', 'res://layouts').replace('.tscn', '.xml')

static func get_all_file(path, files = []):
	var dirAccess:DirAccess = DirAccess.open(path)
	for file in dirAccess.get_files():
		files.append(dirAccess.get_current_dir().path_join(file))
	var dirs = dirAccess.get_directories()
	for dir in dirs:
		get_all_file(dirAccess.get_current_dir().path_join(dir), files)
	return files
