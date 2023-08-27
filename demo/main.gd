extends Control


@onready var viewer1 = %RiveViewer1 as RiveViewer


func _init() -> void:
	# Print time for debugging
	var date = Time.get_datetime_dict_from_system(false)
	date.period = "pm" if date.hour >= 12 and date.hour != 24 else "am"
	date.hour = (date.hour - 12 if date.hour > 12 else date.hour)
	date.minute = str(date.minute).pad_zeros(2)
	print("{month}/{day}/{year}, {hour}:{minute}{period}\n---\n".format(date))


func _ready() -> void:
	var file: RiveFile = viewer1.get_file()
	if file: prints("# Artboards:", file.get_artboard_count(), file.get_artboards())
	
	var artboard: RiveArtboard = viewer1.get_artboard()
	if artboard: prints("# Scenes: ", artboard.get_scene_count(), artboard.get_scenes())
	
	var scene: RiveScene = viewer1.get_scene()
	if scene: prints(scene.get_listeners())
	
	viewer1.scene_property_changed.connect(_on_scene_property_changed)


func _on_scene_property_changed(_scene: RiveScene, property: String, new_value, old_value) -> void:
	print("Property {prop} changed! {old} -> {new}".format({
		prop = property,
		old = old_value,
		new = new_value
	}))
