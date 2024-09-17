class BoundFrame : public threepp::Group {
public:

    static std::shared_ptr<threepp::Texture> dragTexture;
    static std::shared_ptr<threepp::Texture> resizeTexture;

    BoundFrame();
    bool is2D = true;
    bool raycastOnDrag = false;
    threepp::Vector3 start;
    threepp::Vector3 end;
    std::shared_ptr<threepp::Sprite> dragIcon;
    std::shared_ptr<threepp::Sprite> resizeIcon;
    std::shared_ptr<threepp::LineSegments> frame;
    std::shared_ptr<threepp::BufferGeometry> frameGeo;

    void clearFrame();

    void applyPosAndSize();

    void onDrag(float deltaX, float deltaY, float deltaZ);

    void offset(float dx, float dy, float dz = 0);

    void resize(float dx, float dy, float dz = 0);

    void scaleIcon();

    void scaleIcon(float iconSize);

    void setDim(bool is2D);

    void raycast(const threepp::Raycaster& raycaster, std::vector<threepp::Intersection>& intersects) override;

    static std::shared_ptr<BoundFrame> create();
};
