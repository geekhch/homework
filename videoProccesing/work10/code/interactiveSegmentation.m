function varargout = interactiveSegmentation(varargin)
% INTERACTIVESEGMENTATION MATLAB code for interactiveSegmentation.fig
%      INTERACTIVESEGMENTATION, by itself, creates a new INTERACTIVESEGMENTATION or raises the existing
%      singleton*.
%
%      H = INTERACTIVESEGMENTATION returns the handle to a new INTERACTIVESEGMENTATION or the handle to
%      the existing singleton*.
%
%      INTERACTIVESEGMENTATION('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in INTERACTIVESEGMENTATION.M with the given input arguments.
%
%      INTERACTIVESEGMENTATION('Property','Value',...) creates a new INTERACTIVESEGMENTATION or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before interactiveSegmentation_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to interactiveSegmentation_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help interactiveSegmentation

% Last Modified by GUIDE v2.5 13-May-2019 11:42:13

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @interactiveSegmentation_OpeningFcn, ...
                   'gui_OutputFcn',  @interactiveSegmentation_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before interactiveSegmentation is made visible.
function interactiveSegmentation_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to interactiveSegmentation (see VARARGIN)
%% initialization 
% input image  
handles.im = im2double(imread('4.jpg')); 
% text  
set(handles.edit_numClusters, 'String', '2'); 
% number of clusters 
handles.k = str2double(get(handles.edit_numClusters, 'String')); 
% pop up menu
label = cell((handles.k)+1, 1); 
label{1} = '请选择标签';
global counter;
counter = cell(handles.k, 1); 
for id = 1 : handles.k
    label{id+1} = [num2str(id)]; 
    counter{id} = 0; 
end 
set(handles.popupmenu_label,'string',  label);
% seed points' location
handles.pixs = cell(handles.k, 1); 
% show images 
axes(handles.axes_input); 
imshow(handles.im); 
axes(handles.axes_output); 
imshow(zeros(size(handles.im))); 
global color;
color = {'r', 'g', 'b', 'y', 'k', 'w', 'm'}; 

% Choose default command line output for interactiveSegmentation
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes interactiveSegmentation wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = interactiveSegmentation_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Get default command line output from handles structure
varargout{1} = handles.output;



function edit_numClusters_Callback(hObject, eventdata, handles)
% hObject    handle to edit_numClusters (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.k = str2double(get(hObject,'String')); 
% Hints: get(hObject,'String') returns contents of edit_numClusters as text
%        str2double(get(hObject,'String')) returns contents of edit_numClusters as a double
label = cell(handles.k+1, 1); 
label{1} = '请选择标签';
global counter;
counter = cell(handles.k, 1); 
for i = 1 : handles.k
    label{i+1} = [num2str(i)]; 
    counter{i} = 0; 
end 
set(handles.popupmenu_label,'string', label);
handles.pixs = cell(handles.k, 1); 
guidata(hObject, handles); 

% --- Executes during object creation, after setting all properties.
function edit_numClusters_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_numClusters (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton_seg.
function pushbutton_seg_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_seg (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[cls, dp] = size(handles.pixs);
[row,col,depth] = size(handles.im);
d_wight=0.7; %设置位置信息权重
% 根据划线坐标提取轨迹数据点
trace = {};
for i=1:cls
    handles.pixs{i} = floor(handles.pixs{i});
    [num,dp] = size(handles.pixs{i});
    trace{i} = [];
    for j=1:num
        p = handles.pixs{i}(j,:);
        if p(1)>0 && p(1)<482 && p(2)>0 && p(2)<322
            try
                trace{i} = [trace{i};[handles.im(p(2),p(1),1) handles.im(p(2),p(1),2) handles.im(p(2),p(1),3) d_wight*p(1)/col d_wight*p(2)/row]];
            catch
                disp(p)
            end
        end
    end
end

%求数据点中心
centers = zeros(cls,5);
for i=1:cls
    centers(i,:) = mean(trace{i});
end
color = [1 0 0;0 1 0;0 0 1;1 1 0;0 0 0;1 1 1;1 0 1];
% 像素点増广坐标位置
points = zeros(row*col,5);
id = 1;

for y=1:row
    for x=1:col
        points(id,:) = [handles.im(y,x,1) handles.im(y,x,2) handles.im(y,x,3) d_wight*x/col d_wight*y/row];
        id = id + 1;
    end
end

% k-means
updated = 1;
out_img = zeros(row,col,3);
c1num = 0;
while updated == 1
    IDX = knnsearch(centers,points);
    id = 1;
    for i=1:row
        for j=1:col
            out_img(i,j,:) = color(IDX(id),:);
            id = id+1;
        end
    end
    axes(handles.axes_output); 
    imshow(out_img);  % 实时显示迭代状态
    pause(0.001);
    % 重新计算中心
    for i=1:cls
        centers(i,:) = mean(points(IDX==i));
    end
    % 判断类型1的点数目是否发生变化从而终止迭代
    if sum(IDX==1)==0 || abs(sum(IDX==1)-c1num)/c1num<0.03 % 允许一定变化率以避免微小震荡
        updated=0;
    else
        c1num = sum(IDX==1);
    end
end
imwrite(out_img,'out_4.jpg');
guidata(hObject, handles); 

% --- Executes on mouse press over figure background, over a disabled or
% --- inactive control, or over an axes background.
function figure1_WindowButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global ButtonDown pos; 
global counter; 
if counter{handles.action} == 0
    handles.pixs{handles.action} = []; 
end 
if strcmp(get(gcf,'SelectionType'),'normal')
    counter{handles.action} = counter{handles.action} + 1; 
    ButtonDown = 1;
    pos = get(handles.axes_input,'CurrentPoint'); 
    handles.pixs{handles.action} = [handles.pixs{handles.action}; pos(1, 1:2)]; 
%     set(handles.text2,'String',num2str(pos(1,1)));
end
guidata(hObject, handles);


% --- Executes on mouse motion over figure - except title and menu.
function figure1_WindowButtonMotionFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global ButtonDown pos; 
global color; 
if ButtonDown==1
    pos0 = get(handles.axes_input,'CurrentPoint');
    line([pos(1,1) pos0(1,1)],[pos(1,2) pos0(1,2)],'LineWidth', 2, 'Color', color{handles.action});
    pos = pos0;
    handles.pixs{handles.action} = [handles.pixs{handles.action}; pos(1, 1:2)]; 
end
guidata(hObject, handles);


% --- Executes on mouse press over figure background, over a disabled or
% --- inactive control, or over an axes background.
function figure1_WindowButtonUpFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global ButtonDown pos;
ButtonDown=[];
pos=[]; 
guidata(hObject, handles); 


% --- Executes on selection change in popupmenu_label.
function popupmenu_label_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu_label (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
contents = cellstr(get(hObject,'String')); 
handles.action = str2double(contents{get(hObject,'Value')}); 
global ButtonDown pos; 
ButtonDown = []; 
pos = []; 
% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu_label contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu_label
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function popupmenu_label_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu_label (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton_reload.
function pushbutton_reload_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_reload (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes_input); 
imshow(handles.im); 
global counter;
for i = 1 : handles.k
    counter{i} = 0;
end
axes(handles.axes_output); 
imshow(zeros(size(handles.im))); 
guidata(hObject, handles);
